using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Reflection;
using Trapeze; 
using BasicFigure;

namespace Task_2_3
{
    public partial class Form1 : Form
    {
        public bool MouseIsDown = false;
        //private bool isCreatCurve = false;
        //private Point[] CurvePoint;
        public Pen HandPen = new Pen(Color.Black);
        public Point ep1, ep2;
        private List<Figure> ShowFigures = new List<Figure>();
        private Stack<Figure> HistoryFigures = new Stack<Figure>();
        private Figure nf;
        private Creat_Figure cr = new Creat_Figure();
        private Graphics g;
        private Paint_Figures pf;

        public Form1()
        {
            InitializeComponent();
            this.g = Holst.CreateGraphics();
            LabelCountPoint.Visible = true;
            CopuntPoint.Visible = true;
            List<BasicFigure.IFigure> plugins = new List<BasicFigure.IFigure>();
            DirectoryInfo pluginDirectory = new DirectoryInfo(System.IO.Path.Combine(Directory.GetCurrentDirectory()));
            if (!pluginDirectory.Exists)
                pluginDirectory.Create();

            //берем из директории все файлы с расширением .dll      
            var pluginFiles = Directory.GetFiles(System.IO.Path.Combine(Directory.GetCurrentDirectory()), "*.dll");
            foreach (var file in pluginFiles)
            {
                //загружаем сборку
                Assembly asm = Assembly.LoadFrom(file);
                //ищем типы, имплементирующие наш интерфейс IPlugin,
                //чтобы не захватить лишнего
                var types = asm.GetTypes().
                            Where(t => t.GetInterfaces().
                            Where(i => i.FullName == typeof(BasicFigure.IFigure).FullName).Any());

                //заполняем экземплярами полученных типов коллекцию плагинов
                foreach (var type in types)
                {
                    Console.WriteLine(type);
                    var plugin = asm.CreateInstance(type.FullName) as BasicFigure.IFigure;
                    plugins.Add(plugin);
                }
            }
            cr.SetList(plugins);
            foreach (var ty in plugins)
            {
                ChouseFigure.Items.Add(ty.Name);
                Console.WriteLine(ty);
            }
            Console.WriteLine("Programm Run");
        }

        private void Holst_MouseDown(object sender, MouseEventArgs e)
        {
            MouseIsDown = true;
            HandPen = new Pen(Color.FromName(PenColorValue.Text), Convert.ToInt32(PenWidthValue.Value));
            ep1 = e.Location;
            ep2 = ep1;
            nf = new Figure(ep1, ep2, HandPen.Color, HandPen.Width, ChouseFigure.Text, Convert.ToInt32(CopuntPoint.Value));
            nf = cr.Creat(nf);


            if (FillColorValue.Text != "None")
            {
                nf.Change_Fill(Color.FromName(FillColorValue.Text));
            }
        }

        private void Holst_MouseMove(object sender, MouseEventArgs e)
        {
            pf = new Paint_Figures(g);
            if (MouseIsDown)
            {
                g.Clear(Holst.BackColor);
                foreach (Figure ef in ShowFigures)
                {
                    pf.Set_Figure(ef);
                    pf.Show(Holst);
                }
                pf.Set_Figure(nf);
                nf.Change_Size(ep1, e.Location);
                pf.Show(Holst);
                ep2.X = e.X;
                ep2.Y = e.Y;
            }
        }

        private void Holst_MouseUp(object sender, MouseEventArgs e)
        {

            MouseIsDown = false;
            ShowFigures.Add(nf);
            HistoryFigures.Clear();
        }

        private void Holst_Paint(object sender, PaintEventArgs e)
        {

        }

        private void UnDoButton_MouseClick(object sender, MouseEventArgs e)
        {
            Figure f = ShowFigures[^1];
            ShowFigures.RemoveAt(ShowFigures.Count - 1);
            g.Clear(Holst.BackColor);
            pf.Set_Figure(f);
            HistoryFigures.Push(f);
            foreach (Figure ef in ShowFigures)
            {
                pf.Set_Figure(ef);
                pf.Show(Holst);
            }
        }

        private void ReDoButton_MouseClick(object sender, MouseEventArgs e)
        {
            if (HistoryFigures.Count > 0)
            {
                Figure f = HistoryFigures.Pop();
                g.Clear(Holst.BackColor);
                pf.Set_Figure(f);
                ShowFigures.Add(f);
                foreach (Figure ef in ShowFigures)
                {
                    pf.Set_Figure(ef);
                    pf.Show(Holst);
                }
            }
        }

        private void ChouseFigure_TextChanged(object sender, EventArgs e)
        {
            if (ChouseFigure.Text == "Line")
            {
                CopuntPoint.Value = 2;
                CopuntPoint.Enabled = false;
            }
            else if (ChouseFigure.Text == "Rectangle")
            {
                CopuntPoint.Value = 4;
                CopuntPoint.Enabled = false;
            }
            else if (ChouseFigure.Text == "Circle")
            {
                CopuntPoint.Value = 60;
                CopuntPoint.Enabled = false;
            }
            else if (ChouseFigure.Text == "Right")
            {
                CopuntPoint.Value = 3;
                CopuntPoint.Enabled = true;
            }
        }

        private async void ButtonSave_Click(object sender, EventArgs e)
        {
            using (FileStream fs = new FileStream("MyJSONFileForFigures.json", FileMode.Create))
            {
                var op = new JsonSerializerOptions { WriteIndented = true };
                //Console.WriteLine(JsonSerializer.Serialize<List<Figure>>(ShowFigures, op));
                await JsonSerializer.SerializeAsync<List<Figure>>(fs, ShowFigures, op);
                //Console.WriteLine("Data has been saved to file");
            }
        }

        private async void ButtonLoad_Click(object sender, EventArgs e)
        {
            // чтение данных
            using (FileStream fs = new FileStream("MyJSONFileForFigures.json", FileMode.OpenOrCreate))
            {
                List<Figure> lf = await JsonSerializer.DeserializeAsync<List<Figure>>(fs);
                string textFromFile = JsonSerializer.Serialize<List<Figure>>(lf);
                ShowFigures.Clear();
                HistoryFigures.Clear();
                for (int i = 0; i < lf.Count; i++)
                {
                    lf[i].isCreat = false;
                    ShowFigures.Add(cr.Creat(lf[i]));
                }

                foreach (Figure ef in ShowFigures)
                {
                    pf.Set_Figure(ef);
                    pf.Show(Holst);
                }
            }
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {

        }
    }
}
