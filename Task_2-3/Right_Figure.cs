using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Task_2_3
{
    class Right_Figure : Figure
    {
        public void Initialization()
        {
            this.Name = "Right";
            this.A = new Point(100, 100);
            this.LX = 50; this.LY = 50;
            this.copunt_point = 6;
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
        public Right_Figure()
        {
            this.Initialization();
        }
        public Right_Figure(Figure f)
        {
            this.Name = "Right";
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
        public Right_Figure(int ex, int ey)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.Creat_Coordinate();
        }
        public Right_Figure(Point ea)
        {
            this.Initialization();
            this.A = ea;
            this.Creat_Coordinate();
        }
        public Right_Figure(Point ep1, Point ep2)
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
        public Right_Figure(Point ep1, Point ep2, Pen pn)
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
        public Right_Figure(Point ep1, Point ep2, Pen pn, int epoint)
        {
            this.Initialization();
            this.A = new Point((ep1.X + ep2.X) / 2, (ep1.Y + ep2.Y) / 2);
            this.LX = Math.Abs(ep1.X - ep2.X) / 2;
            this.LY = Math.Abs(ep1.Y - ep2.Y) / 2;
            this.Left_Top = new Point(A.X - LX, A.Y - LY);
            this.Right_Down = new Point(A.X + LX, A.Y + LY);
            this.copunt_point = epoint;
            this.inj = 360 / this.copunt_point;
            this.coord = new Point[this.copunt_point];
            this.R = new double[this.copunt_point];
            this.pencolor = pn.Color;
            this.penwidth = pn.Width;
            this.Creat_Radius();
            this.Creat_Coordinate();
        }
        public Right_Figure(int ex, int ey, int epoint)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.copunt_point = epoint;
            this.inj = 360 / this.copunt_point;
            this.R = new double[this.copunt_point];
            this.coord = new Point[this.copunt_point];
            this.Creat_Radius();
            this.Creat_Coordinate();
        }
        public Right_Figure(int ex, int ey, int epoint, double er)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.copunt_point = epoint;
            this.inj = 360 / this.copunt_point;
            this.R = new double[this.copunt_point];
            for (int i = 0; i < this.copunt_point; i++) this.R[i] = er;
            this.coord = new Point[this.copunt_point];
            this.Creat_Coordinate();
        }
        public Right_Figure(int ex, int ey, int epoint, Point[] p)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.copunt_point = epoint;
            this.inj = 360 / this.copunt_point;
            this.coord = p;
            this.R = new double[this.copunt_point];
            for (int i = 0; i < epoint; i++)
            {
                this.R[i] = Math.Sqrt(Math.Pow(this.A.X - p[i].X, 2) + Math.Pow(this.A.Y - p[i].Y, 2));
            }
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
