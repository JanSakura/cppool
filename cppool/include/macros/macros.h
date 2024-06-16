#ifndef _CPPOOL_MACROS_H_
#define _CPPOOL_MACROS_H_

#define BEGIN int main(int argc, char* argv[]){
#define END return 0;}
#define CODE_BEGIN do{
#define CODE_END } while(0)

#define CONST_CHARP(x) #x
#define CONCAT(x,y) x##y


#ifdef __cplusplus
#define CLASS_DOMAIN(x) x::
#else
#define CLASS_DOMAIN(x)
#endif // __cplusplus


#endif // !_CPPOOL_MACROS_H_

