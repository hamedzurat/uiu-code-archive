#include <stdio.h>

#define MAX 1000

struct Train {
    char name[MAX];
    int tickets;
    float rating;
};

void addTrain(struct Train listOfTrains[], int numOfTrains) {
    printf("Name of the train: ");
    getchar();
    scanf("%[^\n]s", listOfTrains[numOfTrains].name);

    printf("Total tickets: ");
    scanf("%d", &listOfTrains[numOfTrains].tickets);

    printf("Ratings: ");
    scanf("%f", &listOfTrains[numOfTrains].rating);
}

/*
int mostPopulatTrain(struct Train listOfTrains[], int numOfTrains)
{
    int max = 0;
    for(int i = 1; i < numOfTrains; i++)
        if(listOfTrains[i].tickets>listOfTrains[max].tickets)
            max = i;

    printf("%s",listOfTrains[max].name);
}
*/

int mostPopulatTrain(struct Train listOfTrains[], int numOfTrains) {
    numOfTrains--;
    if(numOfTrains == 0)
        return listOfTrains[numOfTrains].tickets;

    int out = mostPopulatTrain(listOfTrains, numOfTrains);

    if(listOfTrains[numOfTrains].tickets > out)
        return listOfTrains[numOfTrains].tickets;
    else
        return out;
}

void displayAllTrains(struct Train listOfTrains[], int numOfTrains) {
    for(int i = 0; i < numOfTrains; i++) {
        printf("Name of the train: %s\n", listOfTrains[i].name);
        printf("Total tickets: %d\n", listOfTrains[i].tickets);
        printf("Ratings: %f\n", listOfTrains[i].rating);
        printf("\n");
    }
}

int main() {
    struct Train t[MAX];
    int num = 0;

    while(1) {
        printf("1. Add a train\n");
        printf("2. Most Popular Train\n");
        printf("3. List of the trains\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");

        int input;
        scanf("%d", &input);

        if(input == 1) {
            addTrain(t, num);
            num++;
        } else if(input == 2) {
            int max = mostPopulatTrain(t, num);
            int index;

            for(int i = 0; i < num; i++)
                if(t[i].tickets == max) {
                    index = i;
                    break;
                }
            printf("Name of the Most Popular Train: %s\n", t[index].name);
        } else if(input == 3)
            displayAllTrains(t, num);
        else if(input == 4)
            break;
    }

    return 0;
}
