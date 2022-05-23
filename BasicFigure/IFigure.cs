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
using System.Windows;
using System.Reflection;

namespace BasicFigure
{
    public interface IFigure
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
        abstract public void Change_Size(Point ep1, Point ep2);
        abstract public void Change_Fill(Color cl);
        abstract public void Change_Point(Point ep);
        abstract public void RestFigure(IFigure f);
    }
}
