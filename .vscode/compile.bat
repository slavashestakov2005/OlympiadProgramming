set FileName=%1
pdflatex -synctex=1 -interaction=nonstopmode --shell-escape -output-directory=build %FileName%
