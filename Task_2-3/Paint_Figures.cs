using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace Task_2_3
{
    class Paint_Figures
    {
        public Figure figur;
        Graphics graph;
        public Paint_Figures(Graphics g, Figure f)
        {
            this.graph = g;
            this.figur = f;
        }
        public Paint_Figures(Graphics g)
        {
            this.graph = g;
        }
        public void Set_Figure(Figure f)
        {
            this.figur = f;
        }
        public void Show(Panel p)
        {
            if (this.figur.isFill)
            {
                graph.FillPolygon(new Pen(figur.color_fill).Brush, figur.coord);
            }
            for (int i = 0; i < figur.copunt_point - 1; i++)
            {
                graph.DrawLine(new Pen(figur.pencolor, figur.penwidth), figur.coord[i], figur.coord[i + 1]);
            }
            graph.DrawLine(new Pen(figur.pencolor, figur.penwidth), figur.coord[figur.copunt_point - 1], figur.coord[0]);
        }
        public void Hide(Panel p)
        {
            for (int i = 0; i < figur.copunt_point - 1; i++)
            {
                graph.DrawLine(new Pen(p.BackColor, figur.penwidth), figur.coord[i], figur.coord[i + 1]);
            }
            graph.DrawLine(new Pen(p.BackColor, figur.penwidth), figur.coord[figur.copunt_point - 1], figur.coord[0]);
            if (this.figur.isFill)
            {
                //graph.FillClosedCurve(new Brush();
            }
        }
    }
}
