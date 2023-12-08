// Mutual exclusion lock.
struct spinlock {
  uint locked;       // Is the lock held?

  // For debugging:
  char *name;        // Name of lock.
  struct cpu *cpu;   // The cpu holding the lock.
};

//counting semaphore
struct semaphore{
  struct spinlock lock;
  int count;
  int valid;
};

//os semaphore table type
struct semtab{
  struct spinlock lock;
  struct semaphore sem[NSEM];
};

extern struct semtab semtable;

