typedef struct locks {
    int num[100][3];
    int count;
} Locks;
 
Locks* init(int lockSeq[][3], int n);
 
int numUnlocked(Locks *locks, bool lights[], int m);