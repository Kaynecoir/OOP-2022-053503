using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace WinFormsApp1
{
    class Curve_Figure : Figure
    {
        public void Initialization()
        {
            this.A = new Point(100, 100);
            this.LX = 50; this.LY = 50;
            this.copunt_point = 2;
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
        public Curve_Figure()
        {
            this.Initialization();
        }
        public Curve_Figure(int ex, int ey)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.Creat_Coordinate();
        }
        public Curve_Figure(Point ea)
        {
            this.Initialization();
            this.A = ea;
            this.Creat_Coordinate();
        }
        public Curve_Figure(Point ep1, Point ep2)
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
        public Curve_Figure(Point ep1, Point ep2, Pen pn)
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
        public Curve_Figure(int ex, int ey, int epoint)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.copunt_point = epoint;
            this.R = new double[this.copunt_point];
            this.coord = new Point[this.copunt_point];
            this.Creat_Radius();
            this.Creat_Coordinate();
        }
        public Curve_Figure(int ex, int ey, int epoint, double er)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.copunt_point = epoint;
            this.R = new double[this.copunt_point];
            for (int i = 0; i < this.copunt_point; i++) this.R[i] = er;
            this.coord = new Point[this.copunt_point];
            this.Creat_Coordinate();
        }
        public Curve_Figure(int ex, int ey, int epoint, Point[] p)
        {
            this.Initialization();
            this.A = new Point(ex, ey);
            this.copunt_point = epoint;
            this.coord = p;
            this.R = new double[this.copunt_point];
            for (int i = 0; i < epoint; i++)
            {
                this.R[i] = Math.Sqrt(Math.Pow(this.A.X - p[i].X, 2) + Math.Pow(this.A.Y - p[i].Y, 2));
            }
        }
        public void Creat_Coordinate()
        {
            
        }
        public void Creat_Radius()
        {
            for (int i = 0; i < copunt_point; i++)
            {
                if (this.LX == 0)
                    this.LX += 1;
                if (this.LY == 0)
                    this.LY += 1;
                this.R[i] = Math.Sqrt(Math.Pow(this.A.X - this.coord[i].X, 2) + Math.Pow(this.A.Y - this.coord[i].Y, 2)); 
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
        }
        override public void Change_Point(Point ep)
        {
            Point[] ncoord = new Point[this.copunt_point+1];
            for(int i = 0; i < this.copunt_point; i++)
            {
                ncoord[i] = this.coord[i];
            }
            ncoord[this.copunt_point] = ep;
            this.copunt_point++;
            this.coord = ncoord;
            this.R = new double[this.copunt_point + 1];
            this.Creat_Radius();
        }
    }
}
