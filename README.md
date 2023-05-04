# most_common_string_kokkos
В cpp файлах реализоввны методы
Питоновский файл нужен для теста, он принимает две переменные окружения: максимальный размер строки и кол-во тетстируемых методов (1-6).


Порядок алгоритмов:

1 hash3 параллельная версия

2 Праллельный Алгоритм Рабина-Карпа с предпосчетом хэша всего текста

3 Праллельный Алгоритм Рабина-Карпа без предпосчета хэша всего текста

(4-6) - последовательные версии тех же алгоритмов

7 hash3 omp-версия



[![CPU-32-PATTERN-LENGHT.png](https://i.postimg.cc/PrcXGhjK/CPU-32-PATTERN-LENGHT.png)](https://postimg.cc/HVwD5qj7)



[![CPU-TIME-4.png](https://i.postimg.cc/qBD0n0z0/CPU-TIME-4.png)](https://postimg.cc/mh90fvY6)



[![CPU-TIME-32.png](https://i.postimg.cc/Xqqbh11T/CPU-TIME-32.png)](https://postimg.cc/R6kyJdBR)



[![CPU-TIME-256.png](https://i.postimg.cc/hjSg8tL4/CPU-TIME-256.png)](https://postimg.cc/4KFrsZ2j)



[![CPU-TIME-1024.png](https://i.postimg.cc/D0NTKQtm/CPU-TIME-1024.png)](https://postimg.cc/wRDPXNxd)



[![CPU-GPU-RATIO.png](https://i.postimg.cc/FKbNJLJn/CPU-GPU-RATIO.png)](https://postimg.cc/QBMR2Vmp)


[![gpu-time.png](https://i.postimg.cc/8C4d6bLy/gpu-time.png)](https://postimg.cc/Y44mcYng)

