#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

using namespace std;

namespace phone_number {
class phone_number {
   private:
    string n;

   public:
    string number();
    phone_number(string num);
};
}  // namespace phone_number

#endif  // PHONE_NUMBER_H