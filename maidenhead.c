#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* Note: don't forget to compile with -lm flags */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

struct position {
    /* Simple structure to store a lat/lon coordinate pair */
    double latitude;
    double longitude;
};

int positionToMaidenhead(struct position *p, char m[])
{
    const int pairs=6;
    const double scaling[]={360.,360./18.,(360./18.)/10.,
        ((360./18.)/10.)/24.,(((360./18.)/10.)/24.)/10.,
        ((((360./18.)/10.)/24.)/10.)/24.,
    (((((360./18.)/10.)/24.)/10.)/24.)/10.};
    int i;
    int index;
    
    for (i=0;i<pairs;i++)
    {
        index = (int)floor(fmod((180.0+p->longitude),
        scaling[i])/scaling[i+1]);
        m[i*2] = (i&1) ? 0x30+index : (i&2) ? 0x61+index : 0x41+index;
        index = (int)floor(fmod((90.0+p->latitude),
        (scaling[i]/2))/(scaling[i+1]/2));
        m[i*2+1] = (i&1) ? 0x30+index : (i&2) ? 0x61+index : 0x41+index;
    }
    m[pairs*2]=0;
    return EXIT_SUCCESS;
}

int main (int argc, char *argv[])
{
    struct position p;
    char m[9];
    
    if (argc!=3)
    {
        return EXIT_FAILURE;
    }
    else
    {
        p.latitude=atof(argv[1]);
        p.longitude=atof(argv[2]);
        if (!positionToMaidenhead(&p,m))
        {
            printf("%s\n", m);
            exit (EXIT_SUCCESS);
            
        }
        else 
        { 
            exit (EXIT_FAILURE);
        }
    }
}
