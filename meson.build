project('quiz', 'cpp',
    default_options : ['cpp_std=c++17'],
    version : '0.1.0',
    license : 'MIT')

#add_global_arguments('-DSOME_TOKEN=value', language : 'cpp')
#c = run_command('sh', 'setup-mongocxx.sh', check: true)

sqlite_dep = dependency('sqlite3')

c = run_command('python', 'grabber.py', check: true)
sources = c.stdout().strip().split(' ')
e = executable('quiz', sources, dependencies : sqlite_dep)
