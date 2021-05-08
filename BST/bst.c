//
// Created by Alpar on 5/8/2021.
//

#include "bst.h"

Node *create(int value) {
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
    return root;
}

Node *insert(Node *tree, int key) {
    if (tree == NULL)
        return create(key);

    /* Otherwise, recur down the tree */
    if (key < tree->day)
        tree->left = insert(tree->left, key);
    else
        tree->right = insert(tree->right, key);

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

    if(!Find(root,key)){
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
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
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

void inorder(Node *root) {
    //rekurziv meghivasokkal megyunk vegig
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->day);
        inorder(root->right);
    }
}

void test() {
    Node *root = NULL;

    int temp;
    for (int i = 0; i < 5; i++) {
        printf("Datum: \n");
        scanf("%d", &temp);
        root = insert(root, temp);
    }
    inorder(root);
    Delete(root, 11);
    inorder(root);
    printf(Find(root, 12) ? "Yes" : "No");
}