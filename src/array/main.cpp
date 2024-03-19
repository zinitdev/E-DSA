#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 100
using namespace std;

// Define struct
struct Array
{
    int arr[MAX], size;
};

// Display array
void display(const Array core)
{
    for (int i = 0; i < core.size; i++)
        cout << core.arr[i] << "\t";
    cout << endl;
}

// Initialize random elements for array
void initArr(Array &core)
{
    cout << "Enter size: ";
    cin >> core.size;

    srand(time(NULL));

    for (int i = 0; i < core.size; i++)
        core.arr[i] = rand() % 100 + 1;

    display(core);
}

// Check array is empty
bool isEmpty(const Array core)
{
    return core.size == 0;
}

// Add element to the first array
void addFirst(Array &core, int value)
{
    if (!isEmpty(core))
    {
        for (int i = core.size; i > 0; i--)
            core.arr[i] = core.arr[i - 1];

        core.arr[0] = value;
        core.size++;
    }
    else
    {
        core.arr[0] = value;
        core.size++;
    }
}

// Add element to the last array
void addLast(Array &core, int value)
{
    if (!isEmpty(core))
    {
        core.arr[core.size] = value;
        core.size++;
    }
    else
        addFirst(core, value);
}

// Add elements at position
void addAtPos(Array &core, int pos, int value)
{
    if (!isEmpty(core))
    {
        for (int i = core.size; i > pos; i--)
        {
            core.arr[i] = core.arr[i - 1];
        }

        core.arr[pos] = value;
        core.size++;
    }
    else
        addFirst(core, value);
}

// Delete element from first array
void removeFirst(Array &core)
{
    if (!isEmpty(core))
    {
        for (int i = 0; i < core.size - 1; i++)
            core.arr[i] = core.arr[i + 1];

        core.size--;
    }
    else
        cout << "Array is empty" << endl;
}

// Delete element from last array
void removeLast(Array &core)
{
    if (!isEmpty(core))
    {
        core.size--;
    }
    else
        cout << "Array is empty" << endl;
}

// Delete element at position
void removeAtPos(Array &core, int pos)
{
    if (!isEmpty(core))
    {
        for (int i = pos; i < core.size - 1; i++)
            core.arr[i] = core.arr[i + 1];

        core.size--;
    }
    else
        cout << "Array is empty" << endl;
}

// Update element value
void updateArr(Array &core, int pos, int value)
{
    if (!isEmpty(core))
    {
        if (pos >= 0 && pos < core.size)
        {
            core.arr[pos] = value;
        }
        else
            cout << "Postion is invalid, Try again!" << endl;
    }
    else
        addFirst(core, value);
}

int main()
{
    Array arr;

    initArr(arr);

    addFirst(arr, 3);
    display(arr);

    addLast(arr, 5);
    display(arr);

    addAtPos(arr, 2, 10);
    display(arr);

    removeFirst(arr);
    display(arr);

    removeLast(arr);
    display(arr);

    removeAtPos(arr, 4);
    display(arr);

    updateArr(arr, 0, 5);
    display(arr);

    return 0;
}