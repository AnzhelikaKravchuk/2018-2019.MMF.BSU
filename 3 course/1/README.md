## Введение в С#

[Рейтинг языков программирования TIOBE](https://www.tiobe.com/tiobe-index/)

[Немного про .NET Framework и .NET Core](https://habr.com/company/microsoft/blog/343804/) 

![](https://github.com/AnzhelikaKravchuk/2018-2019.MMF.BSU/blob/master/3%20course/Pictures/1.%20%D0%92%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5%20%D0%B2%20C%23.png)
  - Hello, World! в C#
    - Создание, редактирование, компиляция и выполнение исходного кода на C# (Notepad или WordPad on Windows, TextEdit on Mac/OS X, or vi on Linux) 
    
              class HelloWorld
              {
	           static void Main() => System.Console.WriteLine("Hello, world!");
              }        
      
    - C Dotnet CLI ([Команда dotnet](https://docs.microsoft.com/ru-ru/dotnet/core/tools/dotnet?tabs=netcore21https://docs.microsoft.com/ru-ru/dotnet/core/tools/dotnet?tabs=netcore21)) ([Кроссплатформенный интерфейс командной строки PowerShell](https://github.com/PowerShell/PowerShell))
    
    
              Example:
	      	mkdir ./HelloWorld
	      	cd ./HelloWorld
	      	dotnet new console
	      	dotnet run
		
	      dotnet command
	      ---------------------------------------------------------------------------
	      
	      dotnet -help
	      ============
	      
	      .NET Command Line Tools (2.1.302)
	      Usage: dotnet [runtime-options] [path-to-application]
	      Usage: dotnet [sdk-options] [command] [arguments] [command-options]
	      
	      path-to-application:
	      
	      The path to an application .dll file to execute.
	      
	      SDK commands:
	      ============
	      new              Initialize .NET projects.
	      restore          Restore dependencies specified in the .NET project.
	      run              Compiles and immediately executes a .NET project.
	      build            Builds a .NET project.
	      publish          Publishes a .NET project for deployment (including the runtime).
	      test             Runs unit tests using the test runner specified in the project.
	      pack             Creates a NuGet package.
	      migrate          Migrates a project.json based project to a msbuild based project
	      clean            Clean build output(s).
	      sln              Modify solution (SLN) files.
	      add              Add reference to the project.
	      remove           Remove reference from the project.
	      list             List references of a .NET project.
	      nuget            Provides additional NuGet commands.
	      msbuild          Runs Microsoft Build Engine (MSBuild).
	      vstest           Runs Microsoft Test Execution Command Line Tool.
	      store            Stores the specified assemblies in the runtime store.
	      tool             Install or work with tools that extend the .NET experience.
	      build-server     Interact with servers started by a build.
	      help             Show help.
	      
	      Common options:
	      ============
	      -v|--verbosity        Set the verbosity level of the command. Allowed values are q[uiet], m[inimal], n[ormal], d[etailed], and diag[nostic].
	      -h|--help             Show help.
	      
	      Run 'dotnet COMMAND --help' for more information on a command.
	      
	      sdk-options:
  	      --version        Display .NET Core SDK version in use.
   	      --info           Display .NET Core information.
              --list-sdks      Display the installed SDKs.
	      --list-runtimes  Display the installed runtimes.
	      -d|--diagnostics Enable diagnostic output.
	      
	      runtime-options:
	      ============
	      --additionalprobingpath <path>    Path containing probing policy and assemblies to probe for.
	      --fx-version <version>            Version of the installed Shared Framework to use to run the application.
	      --roll-forward-on-no-candidate-fx Roll forward on no candidate shared framework is enabled.
	      --additional-deps <path>          Path to additional deps.json file.
	      
	      Additional tools ('dotnet [tool-name] --help' for more information):
	      ===================================================================
	      
	      dev-certs      Create and manage development certificates.
	      ef             Entity Framework Core command-line tools.
	      sql-cache      SQL Server cache command-line tools.
	      user-secrets   Manage development user secrets.
	      watch          Start a file watcher that runs a command when files change.

    - C Visual Studio 2017 ([Скачайте Visual Studio](https://visualstudio.microsoft.com/ru/downloads/?rr=https%3A%2F%2Fwww.google.by%2F))
    - Создание Solution и Project
    - Компиляция и выполнение
  - Основы синтаксиса C#
    - Ключевые слова C#
    - Идентификаторы
  - Работа с переменными

## Лабораторная работа 1 

*Последний срок сохранения изменений на github.com: ##.##, ##.##.18.*

*Срок защиты лабораторной работы:  ##.##.18.*

### Теория:  

### Задача: 
