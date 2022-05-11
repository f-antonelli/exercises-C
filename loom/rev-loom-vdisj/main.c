int no_son_disjuntos(int *vec1,int *vec2)
{
    int i=0,j=0;
    while(i<TAM1 && j<TAM2)
    {
        if(*vec1<*vec2)
        {
            vec1++;
            i++;
        }
        else if(*vec1>*vec2)
        {
            vec2++;
            j++;
        }
        else
            return VERDADERO;
    }
    while(i<TAM1)
    {
        if(*vec1<*vec2)
            vec1++;
        else if(*vec1>*vec2)
            return 1;
        else
            return VERDADERO;
        i++;
    }
    while(j<TAM2)
    {
        if(*vec2<*vec1)
            vec2++;
        else if(*vec2>*vec1)
            return 1;
        else
            return VERDADERO;
        j++;
    }
    return 1;
}
