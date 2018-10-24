from csv import reader
from contextlib import redirect_stdout
from collections import namedtuple

from anytree import Node, RenderTree
from anytree.exporter import DotExporter # sudo apt install graphviz
import pydotplus

Entrada = namedtuple("Entrada", "cod_geral area_geral cod_especifica area_especifica cod_detalhada area_detalhada codigo rotulo")
raiz = Node("Disciplinas")

with open("dataset.csv", encoding="utf-8") as csvfile:
    cod_geral = ""
    cod_especifica = ""
    cod_detalhada = ""
    csvfile.readline()
    for line in reader(csvfile, delimiter=";"):
        entrada = Entrada(*line)
        if entrada.cod_geral != cod_geral:
            area_geral = Node("{} {}".format(entrada.cod_geral, entrada.area_geral), parent=raiz)
            # print("==== Área geral: {} {}".format(entrada.cod_geral, entrada.area_geral))
            cod_geral = entrada.cod_geral
        if entrada.cod_especifica != cod_especifica:
            cod_especifica = entrada.cod_especifica
            # print("---- Área específica: {} {}".format(entrada.cod_especifica, entrada.area_especifica))
            area_especifica = Node("{} {}".format(entrada.cod_especifica, entrada.area_especifica), parent=area_geral)
        if entrada.cod_detalhada != cod_detalhada:
            cod_detalhada = entrada.cod_detalhada
            # print("++++ Área detalhada: {} {}".format(entrada.cod_detalhada, entrada.area_detalhada))
            area_especifica = Node("{} {}".format(entrada.cod_detalhada, entrada.area_detalhada), parent=area_especifica)
        # print("{} {}".format(entrada.codigo, entrada.rotulo))
        normais = Node(entrada.rotulo, parent=area_especifica)

for pre, fill, node in RenderTree(raiz):
    print("%s%s" % (pre, node.name))

DotExporter(raiz).to_dotfile("tree.dot")
graph = pydotplus.graph_from_dot_file("tree.dot")
graph.write_pdf("tree.pdf")