/**
 * @file
 * @brief [Huffman Coding](https://en.wikipedia.org/wiki/Huffman_coding)
 * compression algorithm implementation.
 * @details
 * Huffman coding is a lossless data compression algorithm that assigns
 * variable-length binary codes to characters based on their frequencies.
 * Characters that occur more frequently are assigned shorter codes, while
 * less frequent characters get longer codes. This greedy approach ensures
 * an optimal prefix-free code, meaning no code is a prefix of another.
 *
 * ### Algorithm
 * 1. Count the frequency of each character in the input.
 * 2. Create a leaf node for each character and add it to a min-heap
 *    (priority queue) ordered by frequency.
 * 3. While the heap has more than one node:
 *    - Extract the two nodes with the lowest frequency.
 *    - Create a new internal node with these two as children and frequency
 *      equal to the sum of their frequencies.
 *    - Insert the new node back into the heap.
 * 4. The remaining node is the root of the Huffman tree.
 * 5. Traverse the tree to assign binary codes (left = '0', right = '1').
 *
 * ### Complexity
 * - Time: O(n log n) where n is the number of unique characters.
 * - Space: O(n) for the tree and code storage.
 *
 * @author [Diogo Ribeiro](https://github.com/diogo)
 */

#include <assert.h>   /// for assert
#include <stdio.h>    /// for IO operations
#include <stdlib.h>   /// for dynamic memory allocation
#include <string.h>   /// for string operations

#define MAX_TREE_NODES 256 ///< maximum number of unique characters (extended ASCII)
#define MAX_CODE_LEN 256   ///< maximum length of a Huffman code

/**
 * @brief Node structure for the Huffman tree
 */
typedef struct Node
{
    char character;        ///< character stored in this node ('\0' for internal)
    unsigned frequency;    ///< frequency of the character or sum of children
    struct Node *left;     ///< pointer to the left child
    struct Node *right;    ///< pointer to the right child
} Node;

/**
 * @brief Min-heap (priority queue) structure for building the Huffman tree
 */
typedef struct MinHeap
{
    unsigned size;                  ///< current number of elements in the heap
    Node *nodes[MAX_TREE_NODES];   ///< array of node pointers
} MinHeap;

/**
 * @brief Structure to store the Huffman code for a character
 */
typedef struct HuffmanCode
{
    char code[MAX_CODE_LEN]; ///< binary string representation of the code
    int is_set;              ///< flag indicating whether a code has been assigned
} HuffmanCode;

/**
 * @brief Creates a new Huffman tree node
 * @param character the character to store
 * @param frequency the frequency of the character
 * @returns pointer to the newly created node
 */
Node *create_node(char character, unsigned frequency)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief Swaps two node pointers
 * @param a pointer to the first node pointer
 * @param b pointer to the second node pointer
 */
void swap_nodes(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Restores the min-heap property by sifting down from the given index
 * @param heap pointer to the min-heap
 * @param idx index to sift down from
 */
void heapify_down(MinHeap *heap, unsigned idx)
{
    unsigned smallest = idx;
    unsigned left = 2 * idx + 1;
    unsigned right = 2 * idx + 2;

    if (left < heap->size &&
        heap->nodes[left]->frequency < heap->nodes[smallest]->frequency)
    {
        smallest = left;
    }
    if (right < heap->size &&
        heap->nodes[right]->frequency < heap->nodes[smallest]->frequency)
    {
        smallest = right;
    }

    if (smallest != idx)
    {
        swap_nodes(&heap->nodes[idx], &heap->nodes[smallest]);
        heapify_down(heap, smallest);
    }
}

/**
 * @brief Restores the min-heap property by sifting up from the given index
 * @param heap pointer to the min-heap
 * @param idx index to sift up from
 */
void heapify_up(MinHeap *heap, unsigned idx)
{
    while (idx > 0)
    {
        unsigned parent = (idx - 1) / 2;
        if (heap->nodes[idx]->frequency < heap->nodes[parent]->frequency)
        {
            swap_nodes(&heap->nodes[idx], &heap->nodes[parent]);
            idx = parent;
        }
        else
        {
            break;
        }
    }
}

/**
 * @brief Inserts a node into the min-heap
 * @param heap pointer to the min-heap
 * @param node pointer to the node to insert
 */
void heap_insert(MinHeap *heap, Node *node)
{
    heap->nodes[heap->size] = node;
    heapify_up(heap, heap->size);
    heap->size++;
}

/**
 * @brief Extracts the node with the minimum frequency from the min-heap
 * @param heap pointer to the min-heap
 * @returns pointer to the node with the minimum frequency
 */
Node *heap_extract_min(MinHeap *heap)
{
    Node *min_node = heap->nodes[0];
    heap->size--;
    heap->nodes[0] = heap->nodes[heap->size];
    heapify_down(heap, 0);
    return min_node;
}

/**
 * @brief Recursively generates Huffman codes by traversing the tree
 * @param node current node in the Huffman tree
 * @param codes array of HuffmanCode structures to store results
 * @param current_code buffer holding the code being built
 * @param depth current depth in the tree (length of current code)
 */
void generate_codes(Node *node, HuffmanCode codes[], char current_code[],
                    int depth)
{
    if (node == NULL)
    {
        return;
    }

    /* leaf node: store the code for this character */
    if (node->left == NULL && node->right == NULL)
    {
        current_code[depth] = '\0';
        strcpy(codes[(unsigned char)node->character].code, current_code);
        codes[(unsigned char)node->character].is_set = 1;
        return;
    }

    /* traverse left subtree with '0' */
    current_code[depth] = '0';
    generate_codes(node->left, codes, current_code, depth + 1);

    /* traverse right subtree with '1' */
    current_code[depth] = '1';
    generate_codes(node->right, codes, current_code, depth + 1);
}

/**
 * @brief Recursively frees all nodes of the Huffman tree
 * @param node root of the tree (or subtree) to free
 */
void free_tree(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

/**
 * @brief Builds a Huffman tree from the input string and generates codes
 * @param text input string to encode
 * @param codes array of HuffmanCode structures to store the generated codes
 * @returns pointer to the root of the Huffman tree, or NULL if input is empty
 */
Node *huffman_build(const char *text, HuffmanCode codes[])
{
    unsigned freq[MAX_TREE_NODES] = {0};
    unsigned len = (unsigned)strlen(text);

    if (len == 0)
    {
        return NULL;
    }

    /* count character frequencies */
    for (unsigned i = 0; i < len; i++)
    {
        freq[(unsigned char)text[i]]++;
    }

    /* count unique characters */
    unsigned unique_count = 0;
    for (int i = 0; i < MAX_TREE_NODES; i++)
    {
        if (freq[i] > 0)
        {
            unique_count++;
        }
    }

    /* build min-heap from frequency table */
    MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < MAX_TREE_NODES; i++)
    {
        if (freq[i] > 0)
        {
            heap_insert(&heap, create_node((char)i, freq[i]));
        }
    }

    /* special case: single unique character */
    if (unique_count == 1)
    {
        Node *leaf = heap_extract_min(&heap);
        Node *root = create_node('\0', leaf->frequency);
        root->left = leaf;

        char current_code[MAX_CODE_LEN];
        generate_codes(root, codes, current_code, 0);
        return root;
    }

    /* build the Huffman tree */
    while (heap.size > 1)
    {
        Node *left = heap_extract_min(&heap);
        Node *right = heap_extract_min(&heap);

        Node *parent =
            create_node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        heap_insert(&heap, parent);
    }

    Node *root = heap_extract_min(&heap);

    /* generate codes from the tree */
    char current_code[MAX_CODE_LEN];
    generate_codes(root, codes, current_code, 0);

    return root;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test(void)
{
    /* Test 1: basic string with known frequencies */
    {
        HuffmanCode codes[MAX_TREE_NODES];
        memset(codes, 0, sizeof(codes));

        Node *root = huffman_build("aabbc", codes);

        /* verify all characters received a code */
        assert(codes[(unsigned char)'a'].is_set == 1);
        assert(codes[(unsigned char)'b'].is_set == 1);
        assert(codes[(unsigned char)'c'].is_set == 1);

        /* 'a' and 'b' have frequency 2, 'c' has frequency 1 */
        /* 'c' should have a longer or equal code than 'a' and 'b' */
        assert(strlen(codes[(unsigned char)'c'].code) >=
               strlen(codes[(unsigned char)'a'].code));
        assert(strlen(codes[(unsigned char)'c'].code) >=
               strlen(codes[(unsigned char)'b'].code));

        /* all codes must be non-empty */
        assert(strlen(codes[(unsigned char)'a'].code) > 0);
        assert(strlen(codes[(unsigned char)'b'].code) > 0);
        assert(strlen(codes[(unsigned char)'c'].code) > 0);

        free_tree(root);
    }

    /* Test 2: verify prefix-free property */
    {
        HuffmanCode codes[MAX_TREE_NODES];
        memset(codes, 0, sizeof(codes));

        Node *root = huffman_build("aaabbbccddddeeeeee", codes);

        /* collect all assigned codes */
        char *assigned[MAX_TREE_NODES];
        int count = 0;
        for (int i = 0; i < MAX_TREE_NODES; i++)
        {
            if (codes[i].is_set)
            {
                assigned[count++] = codes[i].code;
            }
        }

        /* verify no code is a prefix of another */
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if (i != j)
                {
                    assert(strncmp(assigned[i], assigned[j],
                                   strlen(assigned[i])) != 0);
                }
            }
        }

        free_tree(root);
    }

    /* Test 3: single character string */
    {
        HuffmanCode codes[MAX_TREE_NODES];
        memset(codes, 0, sizeof(codes));

        Node *root = huffman_build("aaaa", codes);

        assert(codes[(unsigned char)'a'].is_set == 1);
        assert(strlen(codes[(unsigned char)'a'].code) > 0);

        /* only 'a' should have a code */
        int set_count = 0;
        for (int i = 0; i < MAX_TREE_NODES; i++)
        {
            if (codes[i].is_set)
            {
                set_count++;
            }
        }
        assert(set_count == 1);

        free_tree(root);
    }

    /* Test 4: two characters with equal frequency */
    {
        HuffmanCode codes[MAX_TREE_NODES];
        memset(codes, 0, sizeof(codes));

        Node *root = huffman_build("ababab", codes);

        assert(codes[(unsigned char)'a'].is_set == 1);
        assert(codes[(unsigned char)'b'].is_set == 1);

        /* both should have codes of length 1 */
        assert(strlen(codes[(unsigned char)'a'].code) == 1);
        assert(strlen(codes[(unsigned char)'b'].code) == 1);

        /* codes must be different */
        assert(strcmp(codes[(unsigned char)'a'].code,
                      codes[(unsigned char)'b'].code) != 0);

        free_tree(root);
    }

    /* Test 5: verify optimality - higher frequency chars get shorter codes */
    {
        HuffmanCode codes[MAX_TREE_NODES];
        memset(codes, 0, sizeof(codes));

        /* 'a' x10, 'b' x5, 'c' x2, 'd' x1 */
        Node *root = huffman_build("aaaaaaaaaabbbbbccdd", codes);

        assert(codes[(unsigned char)'a'].is_set == 1);
        assert(codes[(unsigned char)'b'].is_set == 1);
        assert(codes[(unsigned char)'c'].is_set == 1);
        assert(codes[(unsigned char)'d'].is_set == 1);

        /* most frequent character should have the shortest code */
        assert(strlen(codes[(unsigned char)'a'].code) <=
               strlen(codes[(unsigned char)'c'].code));
        assert(strlen(codes[(unsigned char)'a'].code) <=
               strlen(codes[(unsigned char)'d'].code));

        free_tree(root);
    }

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @param argc commandline argument count
 * @param argv commandline array of arguments
 * @returns 0 on exit
 */
int main(int argc, char const *argv[])
{
    if (argc == 2 && strcmp(argv[1], "-test") == 0)
    {
        test();
        return 0;
    }

    char text[1024];
    printf("Enter a string to encode: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }

    /* remove trailing newline */
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n')
    {
        text[len - 1] = '\0';
    }

    if (strlen(text) == 0)
    {
        printf("Empty input. Nothing to encode.\n");
        return 0;
    }

    HuffmanCode codes[MAX_TREE_NODES];
    memset(codes, 0, sizeof(codes));

    Node *root = huffman_build(text, codes);

    printf("\nCharacter\tFrequency\tCode\n");
    printf("---------\t---------\t----\n");

    /* count frequencies for display */
    unsigned freq[MAX_TREE_NODES] = {0};
    for (size_t i = 0; i < strlen(text); i++)
    {
        freq[(unsigned char)text[i]]++;
    }

    for (int i = 0; i < MAX_TREE_NODES; i++)
    {
        if (codes[i].is_set)
        {
            if (i == ' ')
            {
                printf("' '\t\t%u\t\t%s\n", freq[i], codes[i].code);
            }
            else
            {
                printf("'%c'\t\t%u\t\t%s\n", (char)i, freq[i],
                       codes[i].code);
            }
        }
    }

    /* compute and display compression stats */
    unsigned original_bits = (unsigned)strlen(text) * 8;
    unsigned encoded_bits = 0;
    for (size_t i = 0; i < strlen(text); i++)
    {
        encoded_bits +=
            (unsigned)strlen(codes[(unsigned char)text[i]].code);
    }

    printf("\nOriginal size:  %u bits\n", original_bits);
    printf("Encoded size:   %u bits\n", encoded_bits);
    printf("Compression:    %.1f%%\n",
           (1.0 - (double)encoded_bits / original_bits) * 100.0);

    free_tree(root);
    return 0;
}
