#pragma once
//нестандартная, но широко распространенная препроцессорная директива,
//разработанная для контроля за тем, чтобы конкретный исходный файл при
//компиляции подключался строго один раз.

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport) 
#else
#define MATHLIBRARY_API __declspec(dllimport) 
#endif
//Когда символ MATHLIBRARY_EXPORTS определен, символ MATHLIBRARY_API 
//установит модификатор __declspec(dllexport) в объявлениях функций-членов в этом коде. 
//Этот модификатор разрешает экспорт функции библиотекой DLL для использования ее другими приложениями. 
//Если символ MATHLIBRARY_EXPORTS не определен, например, когда файл заголовка включен приложением, 
//символ MATHLIBRARY_API определяет модификатор __declspec(dllimport) в объявлениях функций-членов. 
//Этот модификатор оптимизирует импорт функции в приложении. 
//По умолчанию шаблон нового проекта для библиотеки DLL добавляет символ
//PROJECTNAME_EXPORTS в список определенных символов для проекта DLL. 
//В данном примере символ MATHLIBRARY_EXPORTS определяется при сборке проекта MathLibrary.
//Дополнительная информация dllexport, dllimport.

namespace Math
{
	MATHLIBRARY_API double SinTaylor(double, double);

	//etc.
}