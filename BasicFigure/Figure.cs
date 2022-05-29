using System;
using System.Collections.Generic;
using System.Text;
using System.Text.Json.Serialization;
using System.Drawing;

namespace BasicFigure
{
    [Serializable]
    public class Figure : IFigure//, ICloneable
    {
        public string Name { get; set; }
        [JsonIgnore]
        public int LX { get; set; }
        [JsonIgnore]
        public int LY { get; set; }
        [JsonIgnore]
        public bool isCreat { get; set; }
        public int copunt_point { get; set; }
        public Point[] coord { get; set; }
        [JsonIgnore]
        public Point A { get; set; }
        public Point Left_Top { get; set; }
        public Point Right_Down { get; set; }
        public string str_pencolor { get; set; }
        [JsonIgnore]
        public Color pencolor { get; set; }
        public float penwidth { get; set; }
        public bool isFill { get; set; }
        public string str_color_fill { get; set; }
        [JsonIgnore]
        public Color color_fill { get; set; }
        [JsonIgnore]
        public double[] R { get; set; }
        [JsonIgnore]
        public double inj { get; set; }
        public Figure()
        {
            this.Name = "None";
            this.A = new Point(100, 100);
            this.LX = 50; this.LY = 50;
            this.copunt_point = 2;
            this.coord = new Point[this.copunt_point];
            this.pencolor = Color.Black;
            this.penwidth = 1;
            this.isFill = false;
            this.color_fill = Color.White;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
            this.isCreat = true;
        }
        public Figure(Point ep1, Point ep2, Color pncolor, float pnwidth, string n = "None", int epoint = 2)
        {
            this.Name = n;
            this.copunt_point = epoint;
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
            this.str_pencolor = pncolor.Name;
            this.pencolor = pncolor;
            this.penwidth = pnwidth;
            this.isFill = false;
            this.str_color_fill = Color.White.Name;
            this.color_fill = Color.White;
            this.isCreat = true;
        }
        public Figure(int ecp, Point elt, Point erd, Color epc, float epw, bool eif, Color ecf)
        {
            this.Name = "None";
            this.copunt_point = ecp;
            this.Left_Top = elt;
            this.Right_Down = erd;
            this.pencolor = epc;
            this.penwidth = epw;
            this.isFill = eif;
            this.color_fill = ecf;
        }
        virtual public void Change_Size(Point ep1, Point ep2)
        {
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.Left_Top = new Point(this.A.X - this.LX, this.A.Y - this.LY);
            this.Right_Down = new Point(this.A.X + this.LX, this.A.Y + this.LY);
            // Alternate of Creat_Coordinate
            this.coord[0] = ep1;
            this.coord[1] = ep2;
        }
        virtual public void Change_Fill(Color cl)
        {
            this.isFill = true;
            this.color_fill = cl;
            this.str_color_fill = cl.Name;
        }
        virtual public void Change_Point(Point ep) { }
        virtual public void RestFigure(IFigure f)
        {
            this.Name = f.Name;
            this.isCreat = f.isCreat;
            this.A = f.A;
            this.LX = f.LX; this.LY = f.LY;
            this.copunt_point = f.copunt_point;
            this.inj = 360 / this.copunt_point;
            this.str_pencolor = f.str_pencolor;
            this.pencolor = Color.FromName(f.str_pencolor);
            this.penwidth = f.penwidth;
            this.isFill = f.isFill;
            this.str_color_fill = f.str_color_fill;
            this.color_fill = Color.FromName(f.str_color_fill);
            this.Left_Top = f.Left_Top;
            this.Right_Down = f.Right_Down;
            if (this.isCreat)
            {
                this.coord = new Point[this.copunt_point];
                this.R = new double[this.copunt_point];
                this.Change_Size(Left_Top, Right_Down);
            }
            else
            {
                this.coord = f.coord;
                this.R = f.R;
            }
        }
        //public object Clone() => new Figure();
    }
}

