
#include "func.h"


BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data) {               //на вход подается дерево в которе надо вставить новый элемент и значение ключа нового элемента
    BinTreeIntNode *newNode;                                      //создание нового узла
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;                                    //ключ - целое число из параметров функции
    newNode->left = NULL;                                   //ссылки - нули, поскольку узел будет вставляться на место листа дерева
    newNode->right = NULL;
    BinTreeIntNode *current = t;                                  //текущий узел при поиске
    BinTreeIntNode *parent = t;                                   //его родитель
    if (t == NULL) {                                        //если корень дерева из параметров функции пустой,
        t = newNode;                                        //то корнем становится наш новый узел
    } else{
        while (current->key != data) {                      //пока не найден узел с нужным ключом
            parent = current;                               //присваиваем родительской ссылке значение ссылки на текущий узел
            if (current->key > data) {                      //переключаем ссылку на следующий уровень в зависимости от условия (если меньше - то в левое поддерево и наоборот)
                current = current->left;
                if (current == NULL) {                      //если после добавления текущего узла не существует -> мы находимся в листовом элементе
                    parent->left = newNode;                 //добавляем наследника
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {                      //если после добавления текущего узла не существует -> мы находимся в листовом элементе
                    parent->right = newNode;                //добавляем наследника
                    return t;
                }
            }
        }
    }
    return t;
}

void printBinTree(BinTreeIntNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printBinTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printBinTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

void printBinTreeSearch(BinTreeIntNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            if (root->left)
                printBinTree(root->left);
            if (root->right)
                printBinTree(root->right);
        }
    }
}

BinTreeIntNode* getSuccessor(BinTreeIntNode *node) {
    BinTreeIntNode *current = node->right;                                //текущий узел (надо найти самый маленький из больших, поэтому правая ветка)
    BinTreeIntNode *parent = node;                                        //родительский текущего
    BinTreeIntNode *s = node;                                             //наилучший на данный момент элемент

    while (current != NULL) {
        parent = s;                                                 //самый маленький из больших, бежим циклом влево, пока не встретим нулевой узел
        s = current;
        current = current->left;
    }
    if (s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}

bool deleteBinTree(BinTreeIntNode *root, int key) {
    BinTreeIntNode *current = root;                                        //текущий узел для поиска
    BinTreeIntNode *parent = root;                                         //родительский узел для поиска
    bool isLeftChild = true;                                         //является ли удаляемый узел левым или правым потомком своего родителя

    while (current->key != key) {                                    //алгоритм поиска места для вставки.
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL)                                        //если вернулись в пустоту - значит искомого ключа в дереве нет
            return false;
    }
    if (current->left == NULL && current->right == NULL) {          //(первый случай) если найденный узел - листовой -> обнуляем ссылки на наследников
        if (current == root)                                        //если этот лист одновременно еще и корень - дерево перестанет существовать
            root = NULL;
        else if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (current->right == NULL) {                               //(второй случай)если у удаляемого узла - один едиснтвенный потомок
        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if (current->left == NULL) {                               //(второй случай)если у удаляемого узла - один едиснтвенный потомок
        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else {
        BinTreeIntNode *successor = getSuccessor(current);                //удаление узла содержащего полный набор (2 наследника) <getSuccessor> - ищет самый подходящий узел, который моно поставить на место переданного ей
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}


void preOrderTravers(BinTreeIntNode *root) {
    if (root) {                                             //проверка наличия корня и его посещение
        printf("%2d ", root->key);
        preOrderTravers(root->left);                        //проверяем левое поддерево рекурсивным вызовом
        preOrderTravers(root->right);                       //проверяем правое поддерево рекурсивным вызовом
    }
}

void inOrderTravers(BinTreeIntNode *root) {
    if (root) {
        inOrderTravers(root->left);                        //проверяем левое поддерево рекурсивным вызовом
        printf("%2d ", root->key);                          //посещение корня
        inOrderTravers(root->right);                       //проверяем правое поддерево рекурсивным вызовом
    }
}

void postOrderTravers(BinTreeIntNode *root) {
    if (root) {
        postOrderTravers(root->left);                        //проверяем левое поддерево рекурсивным вызовом
        postOrderTravers(root->right);                       //проверяем правое поддерево рекурсивным вызовом
        printf("%2d ", root->key);                          //посещение корня
    }
}


FILE *file;

BinTreeIntNode* balancedTree(int n) {
    BinTreeIntNode *newNode;
    int x;                                      //некий временный узел
    int nL;
    int nR;

    if (n == 0) {
        return NULL;                            //Если нужно построить сбал. дерево из 0 элементов  -> значит мы находимся в листе
    } else {
        fscanf(file, "%d", &x);                 //заполняем узел данными из файла (или массива) и считаем корня насколько большого дерева он станет
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
        newNode->key = x;
        newNode->left = balancedTree(nL);
        newNode->right = balancedTree(nR);
    }
    return newNode;                             //вовзращаем ссылку на корень идеально сбалансированного дерева

}

bool binTreeSearch(BinTreeIntNode *root, int value) {
    if (root == NULL)                                       //проверка существует ли дерево
        return false;
    if (root->key == value)
        return true;                                           //проверка не в корне ли искомое значение

    BinTreeIntNode *current = root;                            //доп переменная флажок, указывает на текущий ключ
    while (current->key != value) {
        if (value < current->key)
            current = current->left;
        else
            current = current->right;

        if (current == NULL)
            return false;
    }
}

void buildTree(int* arr, int new, int size) {                       //массив, индекс добавляемого элемента и размер массива)
    int maxIdx = new;                                              //индекс максимального элемента из сравниваемых родителя и потомка
    int newElem = arr[new];                                        //здесь храним значение добавляемого элемента

    while(true) {
        int child = new * 2 + 1; //left child                      //высчитываем индекс левого потомка
        if((child < size) && (arr[child] > newElem)) {             //проверяем что он не за пределами массива и сравниваем с новым элементом
            maxIdx = child;                                        //если потомок больше - то записываем его в индекс как масимальный
        }
        child = new * 2 + 2; //left child                      //высчитываем индекс правого потомка
        if((child < size) && (arr[child] > arr[maxIdx])) {             //проверяем что он не за пределами массива и сравниваем с новым элементом
            maxIdx = child;                                        //если потомок больше - то записываем его в индекс как масимальный
        }
        if (maxIdx == new)                                         //если максимальным оказался новый элемент то выходим из цикла
            break;
        arr[new] = arr[maxIdx];                                    //если один из потомков оказался больше
        arr[maxIdx] = newElem;                                     //то меняем местами с новым элементом
        new = maxIdx;                                              //чтобы сравнить новый элемент с новыми потомками
    }
}

void heapSort(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0 ; --i) {
        buildTree(arr,i,size);
    }
    while (size > 1) {                                             //пока в дерене не останется 1 элемент
        --size;
        int firstElem = arr[0];                                     //меняем местами нулевой и последний элементы
        arr[0] = arr[size];
        arr[size] = firstElem;
        buildTree(arr,0,size);
    }
}