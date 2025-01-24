#ifndef _CPPOOL_MACROS_H_
#define _CPPOOL_MACROS_H_

#define BEGIN int main(int argc, char* argv[]){
#define END return 0;}
#define CODE_BEGIN do{
#define CODE_END } while(0)

// ת�ַ���
#define CONST_CHARP(x) #x

// ��������
#define CONCAT(x,y) x##y


// ǿ������
#ifdef _MSC_VER // for MSVC
#define forceinline __forceinline
#elif defined __GNUC__ || defined(__GNUG__) // for gcc on Linux/Apple OS X
#define forceinline __inline__ __attribute__((always_inline))
#elif defined(__clang__)
define forceinline __attribute__((always_inline))
#else
#define forceinline inline
#endif

// ��ֹ����,�㺯��(�Լ�д���),��ֹ�Ż�
#if defined(__clang__)
#define NOINLINE __attribute__((noinline))
#define PH_ATTR_NAKED __attribute__((naked))
#elif defined(__GNUC__) || defined(__GNUG__)
#define NOINLINE __attribute__((noinline))
#define PH_ATTR_NAKED __attribute__((naked))
#define OPTS_OFF _Pragma("GCC push_options") \
_Pragma("GCC optimize (\"O0\")")
#define OPTS_ON #pragma GCC pop_options
#elif defined(_MSC_VER)
#define NOINLINE __declspec(noinline)
#define PH_ATTR_NAKED __declspec(naked)
#define OPTS_OFF __pragma(optimize("", off))
#define OPTS_ON __pragma(optimize("", on))
#endif

// ��ҳ��ֶ�
#if defined(_MSC_VER)
#define PAGE_ALIGN(num) __declspec(align(num))
#define SECTION(name) __declspec(code_seg(name))
#define CODE_SECTION_START(name) __pragma(code_seg(name))
#define CODE_SECTION_END __pragma(code_seg())
#elif defined(__clang__) || defined(__GUNC__)
#define PAGE_ALIGN(num) __attribute__((align(num)))
#define SECTION(name) __attribute__(section(name))
#endif

#ifdef __cplusplus
#define CLASS_DOMAIN(x) x::
#else
#define CLASS_DOMAIN(x)
#endif // __cplusplus


#endif // !_CPPOOL_MACROS_H_

