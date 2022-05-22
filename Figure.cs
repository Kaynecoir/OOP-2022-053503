using System;
using System.Collections.Generic;
using System.Text;
using System.Text.Json.Serialization;
using System.Drawing;

namespace WinFormsApp1
{
    [Serializable]
    class Figure
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
        public Figure(Point ep1, Point ep2, Pen pn, string n = "None", int epoint = 2)
        {
            this.Name = n;
            this.copunt_point = epoint;
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
            this.str_pencolor = pn.Color.Name;
            this.pencolor = pn.Color;
            this.penwidth = pn.Width;
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
        virtual public void Change_Size(Point ep1, Point ep2) { }
        virtual public void Change_Fill(Color cl) { }
        virtual public void Change_Point(Point ep) { }
    }
}
