#include <iostream>
#include <vector>
using namespace std;


class odometer  {
    int *reading;
    int length;

    public :

    odometer(int len)
    {

        length=len;
        reading = new int[length];
        initialize();
    }

    void initialize()
    {
        for(int i=0; i<length; i++)
        {
            reading[i]=i+1;
        }
    }

    void printCurrent()
    {
        for(int i=0; i<length; i++)
        {
            cout<<reading[i];
        }
        cout<<endl;
    }

    int * getnext(int *value)
    {
        int incloc= GetIncLoc(value);
        //cout<<"loc is"<<incloc;
        if(incloc==0 )//&& reading[incloc]==9-(length-1))
        {
            for(int i=0; i<length; i++)
            {
                value[i]=i+1;
            }
        }
        else
        {
           value[incloc]++;
           for (int i= incloc+1 ;i<length;i++)
            {
                value[i] = value[i-1]+1;
            }
        }
        return value;
    }


    int * getpre(int *value)
    {
        int incloc= GetDecLoc(value);
        //cout<<"loc is"<<incloc;
        if(incloc==0 && value[incloc]==1)
        {
            for(int i=0; i<length; i++)
            {
                value[i]=9-(length-1);
            }
        }
        else
        {
           value[incloc]--;
           for (int i= incloc+1 ;i<length;i++)
            {
                value[i]=9-(length-1);
            }
        }
        return value;
    }


    void next()
    {
        reading=getnext(reading);
    }
    int GetIncLoc(int *value)
    {
        if(value[length-1]<9)
        {
            return length-1;
        }
        for( int i=length-1; i>0; i--)
        {
            if(value[i-1]+1< value[i])
                return i-1;

        }
    }

    int GetDecLoc(int *value)
    {
        for( int i=length-1; i>0; i--)
        {
            if(value[i-1]+1< value[i])
                return i;

        }
        return 0;
    }


    void pre (int * first)
    {
       reading=getpre(reading);
    }

    bool isLessThanEqual(int *first, int *second)
    {
        for(int i=0; i<length; i++)
        {
            if (first[i] < second[i]) {
                return true;
            }
            else if (first[i] > second[i]) {
                 return false;
            }
        }
        return true;
    }

    bool isSame(int *first, int *second)
    {
        for(int i=0; i<length; i++)
        {
            if (first[i] != second[i])
                return false;
        }
        return true;
    }

    int distance(int *dst)
    {
        int gap=0;
        while (!isSame(reading, dst))
        {
            gap++;
            dst=getpre(dst);
        }
        return gap;
    }
};

int main()
{
    odometer odometerObj(5);
    odometerObj.printCurrent();
    for(int i =0;i<40;i++)
    {
        odometerObj.pre();
        odometerObj.printCurrent();
    }

}
