using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace WinFormsApp1
{
    class Circ_Figure : Figure
    {

        public void Initialization()
        {
            this.Name = "Circle";
            this.A = new Point(100, 100);
            this.LX = 50; this.LY = 50;
            this.copunt_point = 60;
            this.inj = 360 / this.copunt_point;
            this.coord = new Point[this.copunt_point];
            this.R = new double[this.copunt_point];
            this.Creat_Radius();
            this.Creat_Coordinate();
            this.pencolor = Color.Black;
            this.penwidth = 1;
            this.isFill = false;
            this.color_fill = Color.White;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
        }
        public Circ_Figure()
        {
            this.Initialization();
        }
        public Circ_Figure(Figure f)
        {
            this.Name = "Circle";
            this.isCreat = f.isCreat;
            this.A = f.A;
            this.LX = f.LX; this.LY = f.LY;
            this.copunt_point = 60;
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
        public Circ_Figure(int ex, int ey)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.Creat_Coordinate();
        }
        public Circ_Figure(Point ea)
        {
            this.Initialization();
            this.A = ea;
            this.Creat_Coordinate();
        }
        public Circ_Figure(Point ep1, Point ep2)
        {
            this.Initialization();
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
            Creat_Radius();
            Creat_Coordinate();
        }
        public Circ_Figure(Point ep1, Point ep2, Pen pn)
        {
            this.Initialization();
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
            this.pencolor = pn.Color;
            this.penwidth = pn.Width;
            this.Creat_Radius();
            this.Creat_Coordinate();
        }
        public void Creat_Coordinate()
        {
            for (int i = 0; i < copunt_point; i++)
            {
                coord[i].X = Convert.ToInt32(A.X - Math.Sin(inj * i * Math.PI / 180) * R[i]);
                coord[i].Y = Convert.ToInt32(A.Y - Math.Cos(inj * i * Math.PI / 180) * R[i]);
            }
        }
        public void Creat_Radius()
        {
            for (int i = 0; i < copunt_point; i++)
            {
                if (this.LX == 0)
                    this.LX += 1;
                if (this.LY == 0)
                    this.LY += 1;
                double sq = Math.Sqrt(this.LX * this.LX * Math.Pow(Math.Cos(this.inj * i * Math.PI / 180), 2) + this.LY * this.LY * Math.Pow(Math.Sin(this.inj * i * Math.PI / 180), 2));
                this.R[i] = (this.LX * this.LY) / sq;
            }
        }
        override public void Change_Size(Point ep1, Point ep2)
        {
            this.LX = Math.Abs(ep1.X - ep2.X) / 2; 
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.Left_Top = new Point(this.A.X - this.LX, this.A.Y - this.LY);
            this.Right_Down = new Point(this.A.X + this.LX, this.A.Y + this.LY);
            this.Creat_Radius();
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
