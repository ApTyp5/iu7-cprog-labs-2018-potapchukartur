#define        N    4



void sort(const int *const kvo, int *const sorted)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)    
            if (*(kvo + j) > *(sorted + i) && *(kvo + j) != *(sorted + i - 1))
                *(sorted + i) = *(kvo + j);
        
            // Теперь в sorted записаны количества букв по убыванию
}
