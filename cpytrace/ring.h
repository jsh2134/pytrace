#ifndef RING_H
#define RING_H

typedef struct {
  unsigned int size;
  unsigned long generation;
  unsigned char *read, *write, *buf;
} Ring;

Ring *ring_from_memory(unsigned char *buf, unsigned int size);
Ring *ring_init_from_memory(unsigned char *buf, unsigned int size);
Ring *ring_malloc(unsigned int size);

void ring_free(Ring *ring);
void ring_write(Ring *ring, unsigned char *buf, unsigned int size);

typedef struct {
  Ring *ring;
  unsigned long generation;
  unsigned char *last;
} RingReader;

RingReader *reader_malloc(Ring *ring);

void reader_free(RingReader *reader);
int reader_read(RingReader *reader, unsigned char *buf);

#endif // RING_H
