#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
//finding the dimensions of the data
int dimension (){
    ifstream fin;
fin.open("points.txt");
int count = 0,line=0;
char ch;
while (!fin.eof())
{
    fin.get(ch);
    if (ch == ' ')
    {
        count++;
    }

    if (ch == '\n')
    {
        break;
    }
}

  return count+1 ;

}

// function to find out the no of lines of data given
int line_no (){
    ifstream fin;
fin.open("points.txt");
int count = 0;
char ch;
while (!fin.eof())
{
    fin.get(ch);

    if (ch == '\n')
    {
        count++;
    }
}

  return count +1;

}

int main()
{
    // taking the data into arrays
    ifstream file("points.txt");
    int dim = dimension() ;
    int line = line_no();
    float data[dim * line]={0};
    char ch ;
    float x;
    float x1[5],y1[5],z1[5];
    int i=0,j=0;
    float d1=0,d2=0;
    float s1,s2=0;
    float cluster_1[line]={34545};
    float cluster_2[line]={34545};


    while ( file >> x  ) // reading the data into a single array so that we can use that in our program
    {
        data[i]=x;
        i++;

    }

   // declaring random centroid in the space and since k= 2 we give two centroids

    float om1[dim]={0};
    for ( i=0;i<dim ; i++ )
    {
        om1[i]= data[i];
    }


    float om2[dim]={0};
    for ( i=3*dim;i<4*dim ; i++ )
    {
        om2[i-3*dim]= data[i];
        }



i=0;
int k=0;
    //finding distance from ech point to each mean and
    while( i <line*dim)

            {
                for (j=0; j<dim ; j++)
                {
                    d1= d1+ abs (data[i+j]-om1[j]);
                    //finding the distance to 1st centroid
                }

            for (j=0; j<dim ; j++)
                {
                    d2= d2+ abs (data[i+j]-om2[j]);
                    // distance to second centroid

                }

                if (d1 < d2 ) //comparing the distances and forming clusters
                {
                   cluster_1[k]= k;
                    s1++;

                }
                else
                {
                    cluster_2[k]=k;
                    s2++;
                }
                i=i + dim;
                k++;
                d1=0;
                d2=0;
            }

i=0;
float m1[dim]={0},m2[dim]={0};
    while (i<line *dim)
    {

        if (cluster_1[i]!= 34545)
        {
            for (j=0;j<dim; j++)
            {

                m1[j]= m1[j]+data[i+j];

                //cout << m1[i+j]<< " "<< i  <<  " "<< j<<"\n";

            }
        }
        i= i + dim;
        }

i=0;
    while (i<line *dim)
    {

        if (cluster_2[i]!= 34545)
        {
            for (j=0;j<dim; j++)
            {

                m2[j]= m2[j]+data[i+j];


            }
        }
        i= i + dim;
        }


  std ::ofstream file_2;
  file_2.open("clusters.txt");

// calucalting the new mean and writing them into a file
  for (i=0;i<dim ;i++)
  {
      m1[i]=m1[i]/s1;
      file_2 << m1[i] << " ";

  }
  file_2<< "\n";
   for (i=0;i<dim ;i++)
  {
      m2[i]=m2[i]/s2;
      file_2 << m2[i]<< " ";

  }
    return 0;
}

