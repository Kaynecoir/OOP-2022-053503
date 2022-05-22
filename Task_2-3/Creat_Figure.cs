using System;
using System.Collections.Generic;
using System.Text;

namespace Task_2_3
{
    class Creat_Figure
    {
        public Figure Creat(string n)
        {
            Figure e;
            if (n == "Line")
                e = new Line_Figure();
            else if (n == "Rectangle")
                e = new Rect_Figure();
            else if (n == "Circle")
                e = new Circ_Figure();
            else if (n == "Right")
                e = new Right_Figure();
            else
                e = new Figure();
            return e;
        }
        public Figure Creat(Figure f)
        {
            Figure e;
            if (f.Name == "Line")
                e = new Line_Figure(f);
            else if (f.Name == "Rectangle")
                e = new Rect_Figure(f);
            else if (f.Name == "Circle")
                e = new Circ_Figure(f);
            else if (f.Name == "Right")
                e = new Right_Figure(f);
            else
                e = f;
            return e;
        }
    }
}
