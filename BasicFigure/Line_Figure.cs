using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace BasicFigure

{
    [Serializable]
    public class Line_Figure : Figure
    {
        public void Initialization()
        {
            this.Name = "Line";
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
        }
        public Line_Figure()
        {
            this.Initialization();
        }
        public Line_Figure(Figure f)
        {
            this.Name = "Line";
            this.isCreat = f.isCreat;
            this.A = f.A;
            this.LX = f.LX; this.LY = f.LY;
            this.copunt_point = 2;
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
        public Line_Figure(Point ep1, Point ep2)
        {
            this.Initialization();
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
            // Alternate of Creat_Coordinate
            this.coord[0] = ep1;
            this.coord[1] = ep2;
        }/*
        public Line_Figure(Point ep1, Point ep2, Pen pn)
        {
            this.Initialization();
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
            this.pencolor = pn.Color;
            this.penwidth = pn.Width;
            // Alternate of Creat_Coordinate
            this.coord[0] = ep1;
            this.coord[1] = ep2;
        }*/
        override public void Change_Size(Point ep1, Point ep2)
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
        override public void Change_Fill(Color cl)
        {
            this.isFill = true;
            this.color_fill = cl;
            this.str_color_fill = cl.Name;
        }
        override public void Change_Point(Point ep)
        {
            //
        }
    }
}
