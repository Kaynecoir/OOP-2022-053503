using System;
using System.Collections.Generic;
using System.Text;
using System.Text.Json.Serialization;
using System.Drawing;

namespace WinFormsApp1
{
    [Serializable]
    abstract class Alpha_Figure
    {
        public string Name { get; set; }
        [JsonIgnore]
        public int LX { get; set; }
        [JsonIgnore]
        public int LY { get; set; }
        public int copunt_point { get; set; }
        public Point[] coord { get; set; }
        [JsonIgnore]
        public Point A { get; set; }
        public Point Left_Top { get; set; }
        public Point Right_Down { get; set; }
        public Color pencolor { get; set; }
        public float penwidth { get; set; }
        public bool isFill { get; set; }
        public Color color_fill { get; set; }
        public double[] R { get; set; }
        [JsonIgnore]
        public double inj { get; set; }
        public Alpha_Figure()
        {
            this.Name = "None";
            this.A = new Point(100, 100);
            this.LX = 50; this.LY = 50;
            this.copunt_point = 2;
            this.coord = new Point[this.copunt_point];
            this.pencolor = Color.Black;
            this.penwidth = 1;
            //    Pen(Color.Black, 1);
            this.isFill = false;
            this.color_fill = Color.White;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
        }
    }
}
