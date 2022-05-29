using System;
using System.Collections.Generic;
using System.Text;
using BasicFigure;
using System.Reflection;


namespace Task_2_3
{
    class Creat_Figure
    {
        List<IFigure> PossibleFigures = new List<IFigure>();
        public Figure Creat(Figure f)
        {
            foreach (Figure pf in PossibleFigures)
            {
                if(pf.Name == f.Name)
                {
                    Figure nf = pf;
                    nf.RestFigure(f);
                    return nf;
                }
            }
            return f;
        }
        public void SetList(List<IFigure> lf)
        {
            PossibleFigures = lf;
        }
    }
}
