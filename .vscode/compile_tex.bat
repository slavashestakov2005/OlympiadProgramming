set FileName=%1
if not x%FileName:main.tex=%==x%FileName% (
    set FileCompile=main.tex
) else (
    set FileCompile=pdf.tex
)
pdflatex -synctex=1 -interaction=nonstopmode --shell-escape -output-directory=build_tex %FileCompile%
