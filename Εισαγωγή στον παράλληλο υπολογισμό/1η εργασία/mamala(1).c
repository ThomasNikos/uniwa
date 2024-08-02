#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

main(int argc, char **argv)
{
    int my_rank;
    int key = 1;
    int plithos, source, target, i, p, k, m, finres, num, max, finresmax = -1;
    int tag1 = 20, tag2 = 30, tag3 = 40, tag4 = 50, tag5 = 60, tag6 = 70, tag7 = 80, tag8 = 90;
    int data[100];
    int data_loc[100];
    int d[100];
    int lastd[100];
    float finresvar, finresmdiv, var;

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    // The menu : End the programm or continue with more numbers.

    while (key)
    {
        if (my_rank == 0)
        {
            printf("\nType 1 to continue or anything else to exit!\n");
            scanf("%d", &key);
            for (target = 1; target < p; target++)
                MPI_Send(&key, 1, MPI_INT, target, tag1, MPI_COMM_WORLD);
        }
        else
        {
            MPI_Recv(&key, 1, MPI_INT, 0, tag1, MPI_COMM_WORLD, &status);
        }

        if (key != 1)
        {
            MPI_Finalize();
            exit(1);
        }

        /*In the main process (0) getting all the numbers from input in an array
        and then sending it to all the processes in another array.*/

        if (my_rank == 0)
        {
            printf("Give amount of numbers:\n");
            scanf("%d", &plithos);
            printf("Give %d numbers:\n", plithos);
            for (k = 0; k < plithos; k++)
                scanf("%d", &data[k]);
            for (target = 1; target < p; target++)
                MPI_Send(&plithos, 1, MPI_INT, target, tag2, MPI_COMM_WORLD);
            num = plithos / p;
            k = num;
            for (target = 1; target < p; target++)
            {
                MPI_Send(&data[k], num, MPI_INT, target, tag3, MPI_COMM_WORLD);
                k += num;
            }
            for (k = 0; k < num; k++)
                data_loc[k] = data[k];
        }
        else
        {
            MPI_Recv(&plithos, 1, MPI_INT, 0, tag2, MPI_COMM_WORLD, &status);
            num = plithos / p;
            MPI_Recv(&data_loc[0], num, MPI_INT, 0, tag3, MPI_COMM_WORLD, &status);
        }

        /*About M and Max*/

        m = 0;
        max = 0;
        for (k = 0; k < num; k++)
        {
            m = m + data_loc[k];
            if (data_loc[k] > max)
            {
                max = data_loc[k];
            }
        }

        /*Sending M and Max to (0) process.*/

        if (my_rank != 0)
        {
            MPI_Send(&m, 1, MPI_INT, 0, tag4, MPI_COMM_WORLD);
            MPI_Send(&max, 1, MPI_INT, 0, tag4, MPI_COMM_WORLD);
        }
        else
        {

            /*When in 0 process, receiving M and Max. After the calculations,
            we get the final results.*/

            finres = m;
            printf("\n Result of process %d: %d\n", my_rank, m);
            for (source = 1; source < p; source++)
            {
                MPI_Recv(&m, 1, MPI_INT, source, tag4, MPI_COMM_WORLD, &status);
                MPI_Recv(&max, 1, MPI_INT, source, tag4, MPI_COMM_WORLD, &status);
                finres = finres + m;
                if (finresmax < max)
                {
                    finresmax = max;
                }
                printf("\n Result of process %d for m: %d\n", source, m);
                printf("\n Result of process %d for Max: %d\n", source, max);
            }
            finresmdiv = finres / (float)plithos;
            printf("\n\n** a) M: %f **\n", finresmdiv);
            printf("\n** b) Max number: %d **\n\n", finresmax);
        }

        /*About Var.
        When in process 0, send M to all other processes.*/

        if (my_rank == 0)
        {
            for (target = 1; target < p; target++)
            {
                MPI_Send(&finresmdiv, 1, MPI_FLOAT, target, tag5, MPI_COMM_WORLD);
            }
        }
        else
        {
            MPI_Recv(&finresmdiv, 1, MPI_FLOAT, 0, tag5, MPI_COMM_WORLD, &status);
        }

        /*Calculating Var with M.*/

        var = 0;
        for (k = 0; k < num; k++)
        {
            var = var + ((data_loc[k] - finresmdiv) * (data_loc[k] - finresmdiv));
        }

        /*Sending Var to (0) process.*/

        if (my_rank != 0)
        {
            MPI_Send(&var, 1, MPI_FLOAT, 0, tag6, MPI_COMM_WORLD);
        }
        else
        {

            /*When in 0 process, receiving Var. After the calculations,
            we get the final results.*/

            finresvar = var;
            printf("\n Result of process %d: for Var %f\n", my_rank, var);
            for (source = 1; source < p; source++)
            {
                MPI_Recv(&var, 1, MPI_FLOAT, source, tag6, MPI_COMM_WORLD, &status);
                finresvar = finresvar + var;
                printf("\n Result of process %d for Var: %f\n", source, var);
            }
            printf("\n\n** c) Var: %f **\n\n", finresvar / (float)plithos);
        }

        if (my_rank == 0)
        {
            for (target = 1; target < p; target++)
            {
                MPI_Send(&finresmax, 1, MPI_INT, target, tag7, MPI_COMM_WORLD);
            }
        }
        else
        {
            MPI_Recv(&finresmax, 1, MPI_INT, 0, tag7, MPI_COMM_WORLD, &status);
        }

        for (k = 0; k < num; k++)
        {
            d[k] = abs((data_loc[k] - finresmax) * (data_loc[k] - finresmax));
        }

        if (my_rank != 0)
        {
            MPI_Send(&d, num, MPI_INT, 0, tag8, MPI_COMM_WORLD);
        }
        else
        {
            for (k = 0; k < num; k++)
            {
                lastd[k] = d[k];
            }
            i = k;
            for (source = 1; source < p; source++)
            {
                MPI_Recv(&lastd[i], num, MPI_INT, source, tag8, MPI_COMM_WORLD, &status);
                i += num;
            }
            for (k = 0; k < plithos; k++)
            {
                printf("\n** d) D: %d **\n", lastd[k]);
            }
        }
    }

    MPI_Finalize();
    return 0;
}