using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Task_2_3
{
    class Rect_Figure : Figure
    {
        public void Initialization()
        {
            this.Name = "Rectangle";
            this.A = new Point(100, 100);
            this.LX = 50; this.LY = 50;
            this.copunt_point = 4;
            this.coord = new Point[this.copunt_point];
            this.Creat_Coordinate();
            this.pencolor = Color.Black;
            this.penwidth = 1;
            this.isFill = false;
            this.color_fill = Color.White;
            this.Left_Top = new Point(this.A.X - this.LX, this.A.Y - this.LY);
            this.Right_Down = new Point(this.A.X + this.LX, this.A.Y + this.LY);
        }
        public Rect_Figure()
        {
            this.Initialization();
            this.Creat_Coordinate();
        }
        public Rect_Figure(Figure f)
        {
            this.Name = "Rectangle";
            this.isCreat = f.isCreat;
            this.A = f.A;
            this.LX = f.LX; this.LY = f.LY;
            this.copunt_point = 4;
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
        public Rect_Figure(int ex, int ey)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.Left_Top = new Point(this.A.X - this.LX, this.A.Y - this.LY);
            this.Right_Down = new Point(this.A.X + this.LX, this.A.Y + this.LY);
            this.Creat_Coordinate();
        }
        public Rect_Figure(Point ea)
        {
            this.Initialization();
            this.A = ea;
            this.Left_Top = new Point(this.A.X - this.LX, this.A.Y - this.LY);
            this.Right_Down = new Point(this.A.X + this.LX, this.A.Y + this.LY);
            this.Creat_Coordinate();
        }
        public Rect_Figure(Point ep1, Point ep2)
        {
            this.Initialization();
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(this.A.X - this.LX, this.A.Y - this.LY);
            this.Right_Down = new Point(this.A.X + this.LX, this.A.Y + this.LY);
            Creat_Coordinate();
        }
        public Rect_Figure(Point ep1, Point ep2, Pen pn)
        {
            this.Initialization();
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(this.A.X - this.LX, this.A.Y - this.LY);
            this.Right_Down = new Point(this.A.X + this.LX, this.A.Y + this.LY);
            this.pencolor = pn.Color;
            this.penwidth = pn.Width;
            this.Creat_Coordinate();
        }
        public void Creat_Coordinate()
        {
            this.coord[0] = this.Left_Top;
            this.coord[1] = new Point(this.Right_Down.X, this.Left_Top.Y);
            this.coord[2] = this.Right_Down;
            this.coord[3] = new Point(this.Left_Top.X, this.Right_Down.Y);
        }
        override public void Change_Size(Point ep1, Point ep2)
        {
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.Left_Top = new Point(this.A.X - this.LX, this.A.Y - this.LY);
            this.Right_Down = new Point(this.A.X + this.LX, this.A.Y + this.LY);
            this.Creat_Coordinate();
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
