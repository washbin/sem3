#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *left;
  struct node *right;
};
typedef struct node node_t;

node_t *create_new_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));

  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void print_tabs(int tabs) {
  for (int i = 0; i < tabs; i++) {
    printf("\t");
  }
}

void print_tree(node_t *root, int level) {
  if (root == NULL) {
    print_tabs(level);
    printf("----<EMPTY>----\n");
    return;
  }

  print_tabs(level);
  printf("value = %d\n", root->value);
  print_tabs(level);

  printf("left\n");
  print_tabs(level);
  print_tree(root->left, level + 1);

  printf("right\n");
  print_tabs(level);
  print_tree(root->right, level + 1);
}

int main() {
  node_t *root = create_new_node(1);
  node_t *node2 = create_new_node(2);
  node_t *node3 = create_new_node(3);
  node_t *node4 = create_new_node(4);
  node_t *node5 = create_new_node(5);

  root->left = node2;
  root->right = node3;

  node2->left = node4;
  node2->right = node5;

  print_tree(root, 0);

  free(node2);
  free(node3);
  free(node4);
  free(node5);
  free(root);
  return 0;
}
