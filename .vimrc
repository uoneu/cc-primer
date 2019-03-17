set nocompatible
set nu 
set shiftwidth=4  
set softtabstop=4  
set tabstop=4  "tab键的宽度  
set expandtab "用空格替代制表位
set hlsearch
set autoindent  "自动缩进
set cindent
set ignorecase  "搜索忽略大小写
set confirm "在处理未保存或只读文件的时候，弹出确认
"set cursorline  "突出显示当前行
syntax on
set mouse=a
set completeopt=longest,menu "让Vim的补全菜单行为与一般IDE一致


"主题设置
colors molokai
let g:molokai_original = 1


set ruler "显示标尺
set showcmd  "输入的命令显示出来，看的清楚些 


"vundle设置
filetype off                  "required
"set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
"插件
Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'majutsushi/tagbar'
Plugin 'bling/vim-airline'
Plugin 'tpope/vim-fugitive'
Plugin 'Xuyuanp/nerdtree-git-plugin'
Plugin 'suan/vim-instant-markdown'
Plugin 'Valloric/YouCompleteMe'
call vundle#end()            "required
filetype plugin indent on    "required


"NERDTree配置
let NERDTreeWinPos='left'
let NERDTreeWinSize=23
"快捷键
map <F2> :NERDTreeToggle<CR>
"只有一个窗口时，自动退出
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
"autocmd vimenter * NERDTree "使用vim时，自动打开tree
let NERDTreeMouseMode=3 "1.双击　2. 目录双文件单  3.单击


"tagbar配置
let g:tagbar_ctags_bin='ctags'  "ctags程序的路径
let g:tagbar_width=30           "窗口宽度的设置
let g:tagbar_singleclick=1      "只需要click一次tag
nmap <F3> :TagbarToggle<CR>


"vim-airline配置
let g:airline#extensions#branch#enabled = 1
set laststatus=2 "持续显示

"nedtree-git-plugin
let g:NERDTreeIndicatorMapCustom = {
    \ "Modified"  : "☼",
    \ "Staged"    : "✚",
    \ "Untracked" : "✭",
    \ "Renamed"   : "➜",
    \ "Unmerged"  : "═",
    \ "Deleted"   : "✖",
    \ "Dirty"     : "✗",
    \ "Clean"     : "✔︎",
    \ "Unknown"   : "?"
    \ }


"youcompleteme配置
let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/examples/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf=0 "关闭加载.ycm_extra_conf.py提示
let g:ycm_collect_identifiers_from_tags_files=1 " 开启 YCM 基于标签引擎
let g:ycm_min_num_of_chars_for_completion=2 "从第2个键入字符就开始罗列匹配项
let g:ycm_cache_omnifunc=0  "禁止缓存匹配项,每次都重新生成匹配项
let g:ycm_seed_identifiers_with_syntax=1    "语法关键字补全
"跳转到定义处
nnoremap <C-F9> :YcmCompleter GoToDefinitionElseDeclaration<CR> 
let g:syntastic_cpp_compiler = 'g++'  "change the compiler to g++ to support c++11. 
let g:syntastic_cpp_compiler_options = '-std=c++11 -stdlib=libc++'  "set the options of g++ to suport c++11.
let g:ycm_error_symbol = '.'
let g:ycm_warning_symbol = '?'





