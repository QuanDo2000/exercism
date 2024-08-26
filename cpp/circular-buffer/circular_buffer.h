#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

namespace circular_buffer {
template <typename T>
class circular_buffer {
   private:
    T* ptr;
    int _size;
    int _start;
    int _len;

   public:
    circular_buffer(int size);
    ~circular_buffer();
    T read();
    void write(T value);
    void overwrite(T value);
    void clear();
};
}  // namespace circular_buffer

#endif  // CIRCULAR_BUFFER_H