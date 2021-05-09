//
// Created by Alpar on 5/8/2021.
//

#include "bst.h"

Node *create(int value, char *name, char *brand) {
    Node *root;
    root = (Node *) malloc(sizeof(Node));
    if (!root) {
        printf("Sikertelen lefoglalas");
        return 0;
    }
    ///mindent lenullazunk + az erteket felveszi a gyoker info
    root->day = value;
    root->left = NULL;
    root->right = NULL;
    root->reservation = createReservArray(root->day);
    root->reservation->reservations[0] = createReservation(name, brand, root->day);
    return root;
}

Node *insert(Node *tree, int key, char *name, char *brand) {
    if (tree == NULL)
        return create(key, name, brand);

    /* Otherwise, recur down the tree */
    if (key < tree->day)
        tree->left = insert(tree->left, key, name, brand);
    else
        tree->right = insert(tree->right, key, name, brand);

    /* return the (unchanged) node pointer */
    return tree;
}

///Ha megvan true, ha nincs false-t terit vissza
bool Find(Node *root, int value) {
    if (root == NULL) {
        return false;
    }
    if (value == root->day) {
        return true;
    }
    bool result1 = Find(root->left, value);
    if (result1) return true;
    bool result2 = Find(root->right, value);
    return result2;

}

Node *search(Node *root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->day == key)
        return root;

    // Key is greater than root's key
    if (root->day < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

///a legkisebb erteku csomopont visszateritese
Node *minValueNode(struct Node *node) {
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

///legnagyobb erteku csomopont
Node *maxValueNode(struct Node *node) {
    Node *current = node;

    while (current && current->right != NULL)
        current = current->right;

    return current;
}

Node *Delete(Node *root, int key) {
    if (root == NULL)
        return root;

    if (!Find(root, key)) {
        return root;
    }
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->day)
        root->left = Delete(root->left, key);

        // If the key to be deleted
        // is greater than the root's
        // key, then it lies in right subtree
    else if (key > root->day)
        root->right = Delete(root->right, key);

        // if key is same as root's key,
        // then This is the node
        // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return (Node *) temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        Node *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->day = temp->day;

        // Delete the inorder successor
        root->right = Delete(root->right, temp->day);
    }
    return root;
}

void inorderDates(Node *root) {
    //show all scheduled dates
    if (root != NULL) {
        inorderDates(root->left);
        printf("\nDAY: %d (free spaces: %d)\n ", root->day, root->reservation->freeAppointments);
        for (int i = 4 - (*root).reservation->freeAppointments - 1; i >=0; i--) {
            printf("\t%.30s | %.20s\n", (*root).reservation->reservations[i].name,
                   (*root).reservation->reservations[i].brand);
        }
        inorderDates(root->right);
    }
}

bool checkForFreeAppiontment(Node *day) {
    if (day->reservation->freeAppointments > 0) {
        return true;
    }
    return false;
}

void scheduleOnFirstAvaDay(Node **database) {
    //searching for the first available day
    for (int i = 1; i <= 30; i++) {
        if (Find(*database, i)) {
            if (checkForFreeAppiontment(search(*database, i))) {
                printf("\nFirst available day is: %d", i);
                char nameToAdd[30], brandToAdd[20];
                printf("\n\tName: ");
                scanf("%s", nameToAdd);
                printf("\tBrand: ");
                scanf("%s", brandToAdd);
                (*database)->reservation->reservations[4 - (*database)->reservation->freeAppointments] = createReservation(nameToAdd,brandToAdd,i);
                (*database)->reservation->freeAppointments--;
                printf("\nYou succefully added the following appointment:\n\tDay: %.3d\n\t\t%s | %s", (*database)->day,
                       nameToAdd, brandToAdd);
                return;
            }
        } else {
            printf("\nFirst available day is: %d", i);
            char nameToAdd[30], brandToAdd[20];
            printf("\n\tName: ");
            scanf("%s", nameToAdd);
            printf("\tBrand: ");
            scanf("%s", brandToAdd);
            (*database) = insert(*database, i, nameToAdd, brandToAdd);
            (*database)->reservation->freeAppointments--;
            printf("\nYou succefully added the following appointment:\n\tDay: %3d\n\t\t%s | %s", (*database)->day,
                   nameToAdd, brandToAdd);
            return;
        }
    }

}

bool scheduleOnSelectedDay(Node **database){
    int day;
    printf("\nDAY:\n");
    scanf("%d",&day);
    if (Find(*database, day)) {
        if (checkForFreeAppiontment(search(*database, day))) {
            printf("\nFirst available day is: %d", day);
            char nameToAdd[30], brandToAdd[20];
            printf("\n\tName: ");
            scanf("%s", nameToAdd);
            printf("\tBrand: ");
            scanf("%s", brandToAdd);
            (*database)->reservation->reservations[4 - (*database)->reservation->freeAppointments] = createReservation(nameToAdd,brandToAdd,day);
            (*database)->reservation->freeAppointments--;
            printf("\nYou succefully added the following appointment:\n\tDay: %.3d\n\t\t%s | %s", (*database)->day,
                   nameToAdd, brandToAdd);
            return true;
        }
        else{
            printf("\nDay is full!");
            return false;
        }
    }
    char nameToAdd[30], brandToAdd[20];
    printf("\n\tName: ");
    scanf("%s", nameToAdd);
    printf("\tBrand: ");
    scanf("%s", brandToAdd);
    (*database) = insert(*database, day, nameToAdd, brandToAdd);
    (*database)->reservation->freeAppointments--;
    printf("\nYou succefully added the following appointment:\n\tDay: %3d\n\t\t%s | %s", (*database)->day,
           nameToAdd, brandToAdd);
    return true;
}

void deleteDay(Node** database){
    int day;
    printf("\nDAY to delete: ");
    scanf("%d",&day);
    Delete(*database,day);
    printf("\n%d day has been deleted!\n");
}

void test() {
    Node *root = NULL;
    char n[30], b[20];
    strcpy(n, "Lala");
    strcpy(b, "BMW");

    root = insert(root, 1, n, b);
    root->reservation->reservations[1] = createReservation(n,n,1);
    root->reservation->reservations[2] = createReservation(b,b,1);
    root->reservation->freeAppointments -= 2;
    strcpy(n, "LAjcsika");
    strcpy(b, "Renault");
    root->right = create(2,n,b);
    root->right->reservation->reservations[1] = createReservation(n,n,1);
    root->right->reservation->reservations[2] = createReservation(b,b,1);
    root->right->reservation->freeAppointments -= 2;
    inorderDates(root);
    root = Delete(root,2);
    inorderDates(root);
//    for (int i = 0; i < 5; i++) {
//        printf("Datum: \n");
//        scanf("%d", &temp);
//        root = insert(root, temp);
//    }
//    inorderDates(root);
//    Delete(root, 11);
//    inorderDates(root);
//    printf(Find(root, 12) ? "Yes" : "No");
}