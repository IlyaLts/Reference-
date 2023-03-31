/*
====================================================================================
	EXAMPLE
====================================================================================
*/
using System;
using System.Collections;
namespace ConsoleEnum
{
    public class cars : IEnumerator,IEnumerable
    {
       private car[] carlist;
       int position = -1;
       //Create internal array in constructor.
       public cars()
       {
           carlist= new car[6]
           {
               new car("Ford",1992),
               new car("Fiat",1988),
               new car("Buick",1932),
               new car("Ford",1932),
               new car("Dodge",1999),
               new car("Honda",1977)
           };
       }
       //IEnumerator and IEnumerable require these methods.
       public IEnumerator GetEnumerator()
       {
           return (IEnumerator)this;
       }
       //IEnumerator
       public bool MoveNext()
       {
           position++;
           return (position < carlist.Length);
       }
       //IEnumerable
       public void Reset()
       {
           position = -1;
       }
       //IEnumerable
       public object Current
       {
           get { return carlist[position];}
       }
    }
  }
  
/*
OUTPUT:
 
Ford            1992
Fiat            1988
Buick           1932
Ford            1932
Dodge           1999
Honda           1977
*/

/*
====================================================================================
	EXAMPLE 2
====================================================================================
*/
using System;
using System.Collections;
namespace ConsoleEnum
{
    public class cars : IEnumerable
    {
        private car[] carlist;
  
        //Create internal array in constructor.
        public cars()
        {
            carlist= new car[6]
            {
                new car("Ford",1992),
                new car("Fiat",1988),
                new car("Buick",1932),
                new car("Ford",1932),
                new car("Dodge",1999),
                new car("Honda",1977)
            };
        }
        //private enumerator class
        private class  MyEnumerator:IEnumerator
        {
            public car[] carlist;
            int position = -1;

            //constructor
            public MyEnumerator(car[] list)
            {
                carlist=list;
            }
            private IEnumerator getEnumerator()
            {
                return (IEnumerator)this;
            }
            //IEnumerator
            public bool MoveNext()
            {
                position++;
                return (position < carlist.Length);
            }
            //IEnumerator
            public void Reset()
            {
                position = -1;
            }
            //IEnumerator
            public object Current
            {
                get
                {
                    try
                    {
                        return carlist[position];
                    }
                    catch (IndexOutOfRangeException)
                    {
                        throw new InvalidOperationException();
                    }
                }
            }
        }  //end nested class
      public IEnumerator GetEnumerator()
      {
          return new MyEnumerator(carlist);
      }
    }
}