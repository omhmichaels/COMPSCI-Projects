let g:colors_name="notepad16"
set background=light
if version > 580                                                                                                                                       
    hi clear
    if exists("syntax_on")
        syntax reset
    endif
endif

"if has("gui_running") || &t_Co == 88 || &t_Co == 256 || &t_Co == 16
    hi Normal ctermfg=black ctermbg=white
    hi Search ctermfg=Black   ctermbg=Yellow
    hi IncSearch ctermfg=Yellow ctermbg=Yellow
    hi StatusLine ctermfg=white ctermbg=green cterm=bold
    hi StatusLineNC ctermfg=LightGreen ctermbg=DarkGreen
    hi VertSplit ctermfg=DarkBlue ctermbg=DarkBlue
    hi Folded ctermfg=DarkBlue ctermbg=LightBlue
    hi Cursor ctermfg=Red ctermbg=Red
    hi IncSearch ctermfg=red ctermbg=DarkYellow
    hi Pmenu ctermfg=white ctermbg=red
    hi CursorLine ctermbg=cyan
    hi CursorColumn ctermbg=cyan
    hi LineNr ctermfg=Yellow ctermbg=DarkBlue cterm=bold

    hi Todo ctermbg=yellow
    hi Title ctermfg=black
    hi Special ctermfg=DarkYellow

    hi String ctermfg=DarkCyan
    hi Constant ctermfg=DarkCyan
    hi number ctermfg=DarkGreen
    hi Statement ctermfg=DarkYellow
    hi Function ctermfg=magenta
    hi PreProc ctermfg=DarkMagenta
    hi Comment ctermfg=DarkGrey cterm=bold
    hi Type ctermfg=Blue
    hi Error ctermfg=black ctermbg=red
    hi Identifier ctermfg=Magenta
    hi Label ctermfg=Magenta
    syntax on