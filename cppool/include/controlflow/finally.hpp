#ifndef _CPPOOL_CONTROL_FLOW_H_
#define _CPPOOL_CONTROL_FLOW_H_

namespace cppool
{
	namespace controlflow
	{
		/*to some extent, Uses RAII to call a final function on destruction;*/

		// �뿪������ʱִ��FinalActionFunc
		template<typename Func>
		class FinalAction 
		{
		public:
			FinalAction(Func func) :FinalActionFunc(::std::move(func)) {};
			~FinalAction()
			{
				FinalActionFunc();
			}
		private:
			Func FinalActionFunc;
		};

		/* 
		* func can be lambad
		* such as : finally( [&](){do something} )
		*/
		template <typename F>
		FinalAction<F> finally(F f) 
		{
			return FinalAction<F>(f);
		}
	}
}
#endif // _CPPOOL_CONTROL_FLOW_H_