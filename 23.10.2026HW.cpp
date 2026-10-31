#include <iostream>
#include <cstdlib>
using namespace std; 

void fillArr(int* arr, int size, int min, int max) {
    int range = max - min + 1;
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % range + min;
    }
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

void print2d(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        printArr(arr[i], cols);
        cout << endl;
    }
}


/* Task 1 
void addColAt(int** arr, int rows, int& cols, int pos) {
    if (pos < 0 || pos > cols) {
        cout << "Wrong position!" << endl;
        return;
    }

    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols + 1];
        int k = 0;

        for (int j = 0; j < cols + 1; ++j) {
            if (j == pos) {
                newRow[j] = rand() % 21;
            }
            else {
                newRow[j] = arr[i][k];
                k++;
            }
        }
        delete[] arr[i];
        arr[i] = newRow;
    }

    cols++;
}
*/



/* Task 2 

void removeCols(int** arr, int rows, int& cols, int pos) {
    if (pos < 0 || pos >= cols) {
        cout << "Wrong column's number!" << endl;
        return;
    }

    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols - 1];  
        int k = 0;                         

        for (int j = 0; j < cols; ++j) {
            if (j != pos) {             
                newRow[k] = arr[i][j];
                k++;
            }
        }

        delete[] arr[i];
        arr[i] = newRow;
    }

    cols--;
}
*/





/* Task 3 

const int N = 3;

void fillMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = rand() % 10;
}

void printMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

void Down(int m[N][N]) {
    for (int j = 0; j < N; j++) {
        int last = m[N - 1][j];
        m[2][j] = m[1][j];
        m[1][j] = m[0][j];
        m[0][j] = last;
    }
}


void Up(int m[N][N]) {
    for (int j = 0; j < N; j++) {
        int first = m[0][j];
        m[0][j] = m[1][j];
        m[1][j] = m[2][j];
        m[2][j] = first;
    }
}


void Right(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        int last = m[i][2];
        m[i][2] = m[i][1];
        m[i][1] = m[i][0];
        m[i][0] = last;
    }
}


void Left(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        int first = m[i][0];
        m[i][0] = m[i][1];
        m[i][1] = m[i][2];
        m[i][2] = first;
    }
}
*/




/* Task 4 

const int N = 3;

void fillMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = rand() % 10;
}

void printMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}


void transpose(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {  
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}
*/




/* Task 5 

const int LEN = 50;


bool sameText(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;  
        i++;
    }
    return a[i] == b[i];   
}

void addContact(char*** book, int& count) {
    for (int r = 0; r < 2; r++) {
        char** newRow = new char* [count + 1];
        for (int i = 0; i < count; i++) {
            newRow[i] = book[r][i];        
        }
        newRow[count] = new char[LEN];    
        delete[] book[r];
        book[r] = newRow;
    }

    cout << "Name: ";
    cin.getline(book[0][count], LEN);
    cout << "Phone: ";
    cin.getline(book[1][count], LEN);

    count++;
}

void showAll(char*** book, int count) {
    if (count == 0) {
        cout << "None is in the list." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << i << ". " << book[0][i] << " - " << book[1][i] << endl;
    }
}

void findByName(char*** book, int count) {
    char name[LEN];
    cout << "Enter name: ";
    cin.getline(name, LEN);
    for (int i = 0; i < count; i++) {
        if (sameText(book[0][i], name)) {
            cout << "Phone: " << book[1][i] << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void findByPhone(char*** book, int count) {
    char phone[LEN];
    cout << "Enter phone: ";
    cin.getline(phone, LEN);
    for (int i = 0; i < count; i++) {
        if (sameText(book[1][i], phone)) {
            cout << "Name: " << book[0][i] << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void editContact(char*** book, int count) {
    int i;
    cout << "Contact number: ";
    cin >> i;
    cin.ignore();
    if (i < 0 || i >= count) {
        cout << "Wrong number!" << endl;
        return;
    }
    cout << "New name: ";
    cin.getline(book[0][i], LEN);
    cout << "New phone: ";
    cin.getline(book[1][i], LEN);
}

void deleteBook(char*** book, int count) {
    for (int r = 0; r < 2; r++) {
        for (int i = 0; i < count; i++) {
            delete[] book[r][i];
        }
        delete[] book[r];
    }
    delete[] book;
}
*/



/* Task 6 

const int TEXT = 50;
int compareText(char a[], char b[]) {
    int i = 0;
    while (a[i] == b[i] && a[i] != '\0') {
        i++;
    }
    return a[i] - b[i];
}
*/



/* Task 7 */


int** create2d(int rows, int cols) {
    int** m = new int* [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new int[cols];
        fillArr(m[i], cols, -10, 10);
    }
    return m;
}

void delete2d(int** m, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
}

int* flatten(int** m, int rows, int cols) {
    int* arr = new int[rows * cols];
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[k] = m[i][j];
            k++;
        }
    }
    return arr;
}


bool contains(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return true;
    }
    return false;
}


void addUnique(int* res, int& count, int value) {
    if (!contains(res, count, value)) {
        res[count] = value;
        count++;
    }
}







int main()
{
	/* Task 1 
    srand(time(0));

    int rows = 3;
    int cols = 4;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        fillArr(arr[i], cols, 0, 20);
    }
    cout << endl;
    print2d(arr, rows, cols);

    int pos;
    cout << "Enter column position (0 - 4): \n";
    cin >> pos;

    addColAt(arr, rows, cols, pos);

    cout << "\nAfter:" << endl;
    print2d(arr, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    */


    /* Task 2 

    int rows = 6;
    int cols = 8;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        fillArr(arr[i], cols, 0, 20);
    }

    cout << endl;
    print2d(arr, rows, cols);

    int num;
    cout << "Enter column number to remove(0 - 8): \n";
    cin >> num;

    removeCols(arr, rows, cols, num);

    cout << endl;
    print2d(arr, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    */



    /* Task 3 

    srand(time(0));

    int m[N][N];
    fillMatrix(m);

    cout << "Matrix:" << endl;
    printMatrix(m);

    int num, count;
    cout << "1. Down" << endl;
    cout << "2. Up" << endl;
    cout << "3. Right" << endl;
    cout << "4. Left" << endl;
    cin >> num;
    cout << "How many times: ";
    cin >> count;

    for (int k = 0; k < count; k++) {
        if (num == 1) Down(m);
        else if (num == 2) Up(m);
        else if (num == 3) Right(m);
        else if (num == 4) Left(m);
    }

    cout << "After moving: " << endl;
    printMatrix(m);

    */


    /* Task 4 


    int m[N][N];
    fillMatrix(m);

    cout << endl;
    printMatrix(m);

    transpose(m);

    cout << "Transposed: " << endl;
    printMatrix(m);

    */


    /* Task 5

    char*** book = new char** [2];
    book[0] = new char* [0];   
    book[1] = new char* [0];
    int count = 0;

    int choice;
    do {
        cout << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Show list" << endl;
        cout << "3. Find by name" << endl;
        cout << "4. Find by phone number" << endl;
        cout << "5. Edit" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        if (choice == 1) addContact(book, count);
        else if (choice == 2) showAll(book, count);
        else if (choice == 3) findByName(book, count);
        else if (choice == 4) findByPhone(book, count);
        else if (choice == 5) editContact(book, count);

    } while (choice != 0);

    deleteBook(book, count);
 */



     /* Task 6 

    const int COUNT = 5;

    char** names = new char* [COUNT];
    for (int i = 0; i < COUNT; i++) {
        names[i] = new char[TEXT];
    }

    for (int i = 0; i < COUNT; i++) {
        cout << "Enter surname " << i + 1 << ": ";
        cin.getline(names[i], TEXT);
    }

    for (int i = 0; i < COUNT - 1; i++) {
        for (int j = 0; j < COUNT - 1 - i; j++) {
            if (compareText(names[j], names[j + 1]) > 0) {  
                char* temp = names[j];                        
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    cout << "Sorted: " << endl;
    for (int i = 0; i < COUNT; i++) {
        cout << names[i] << endl;
    }

    for (int i = 0; i < COUNT; i++) {
        delete[] names[i];
    }
    delete[] names;
    */



    /* Task 7 */

srand(time(0));

int rA, cA, rB, cB, rC, cC;
cout << "A rows and cols: "; cin >> rA >> cA;
cout << "B rows and cols: "; cin >> rB >> cB;
cout << "C rows and cols: "; cin >> rC >> cC;

int** A = create2d(rA, cA);
int** B = create2d(rB, cB);
int** C = create2d(rC, cC);

cout << "A: " << endl; print2d(A, rA, cA);
cout << "B: " << endl; print2d(B, rB, cB);
cout << "C: " << endl; print2d(C, rC, cC);


int sA = rA * cA, sB = rB * cB, sC = rC * cC;
int* a = flatten(A, rA, cA);
int* b = flatten(B, rB, cB);
int* c = flatten(C, rC, cC);

int total = sA + sB + sC;
int* common = new int[total];
int nCommon = 0;
for (int i = 0; i < sA; i++) {
    if (contains(b, sB, a[i]) && contains(c, sC, a[i])) {
        addUnique(common, nCommon, a[i]);
    }
}


int* unique = new int[total];
int nUnique = 0;
for (int i = 0; i < sA; i++) {
    if (!contains(b, sB, a[i]) && !contains(c, sC, a[i])) addUnique(unique, nUnique, a[i]);
}
for (int i = 0; i < sB; i++) {
    if (!contains(a, sA, b[i]) && !contains(c, sC, b[i])) addUnique(unique, nUnique, b[i]);
}
for (int i = 0; i < sC; i++) {
    if (!contains(a, sA, c[i]) && !contains(b, sB, c[i])) addUnique(unique, nUnique, c[i]);
}

int* commonAC = new int[total];
int nAC = 0;
for (int i = 0; i < sA; i++) {
    if (contains(c, sC, a[i])) {
        addUnique(commonAC, nAC, a[i]);
    }
}

int* negative = new int[total];
int nNeg = 0;
for (int i = 0; i < sA; i++) if (a[i] < 0) addUnique(negative, nNeg, a[i]);
for (int i = 0; i < sB; i++) if (b[i] < 0) addUnique(negative, nNeg, b[i]);
for (int i = 0; i < sC; i++) if (c[i] < 0) addUnique(negative, nNeg, c[i]);


cout << "1. Common for A, B, C: ";  
printArr(common, nCommon);
cout << endl;
cout << "2. Unique: ";              
printArr(unique, nUnique);
cout << endl;
cout << "3. Common for A and C: ";  
printArr(commonAC, nAC);
cout << endl;
cout << "4. Negative: ";            
printArr(negative, nNeg);
cout << endl;


delete2d(A, rA); delete2d(B, rB); delete2d(C, rC);
delete[] a; delete[] b; delete[] c;
delete[] common; delete[] unique; delete[] commonAC; delete[] negative;

}
