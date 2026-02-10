import os

def compruebaArchivo(cadena, archivo):
    archivo_nuevo=""
    if "cadena" in archivo:
        if "_" + cadena in archivo:
            archivo_nuevo = archivo.replace("_" + cadena, '')
        elif "-" + cadena in archivo:
            archivo_nuevo = archivo.replace("-" + cadena, '')

    print(archivo_nuevo)
    return archivo_nuevo


def mueveArchivos():
    home = os.path.expanduser("~")
    Descargas = home + "/Descargas/"
    UGR = home + "/UGR/"
    for path, dirs, files in os.walk(Descargas):
        for arch in files:
            # Asignatura TSI
            if "TSI" in arch:
                arch_nuevo=compruebaArchivo("TSI", arch)
                #BUG, NotADirectoryError if archivo_neuvo = ""
                os.rename(Descargas + arch, UGR + "TSI/" + arch_nuevo)    # @violation
            # Asignatura FBD
            elif "FBD" in arch:
                arch_nuevo=compruebaArchivo("FBD", arch)
                #BUG, NotADirectoryError if archivo_neuvo = ""
                os.rename(Descargas + arch, UGR + "FBD/" + arch_nuevo)    # @violation
            # Asignatura IC
            elif "IC" in arch:
                arch_nuevo=compruebaArchivo("IC", arch)
                #BUG, NotADirectoryError if archivo_neuvo = ""
                os.rename(Descargas + arch, UGR + "IC/" + arch_nuevo)     # @violation
            # Asignatura IA
            elif "IA" in arch:
                arch_nuevo=compruebaArchivo("IA", arch)
                #BUG, NotADirectoryError if archivo_neuvo = ""
                os.rename(Descargas + arch, UGR + "IA/" + arch_nuevo)     # @violation
            # Asignatura AC
            elif "AC" in arch:
                arch_nuevo=compruebaArchivo("AC", arch)
                #BUG, NotADirectoryError if archivo_neuvo = ""
                os.rename(Descargas + arch, UGR + "AC/" + arch_nuevo)     # @violation
            # Asignatura ALG
            elif "ALG" in arch:
                arch_nuevo=compruebaArchivo("ALG", arch)
                #BUG, NotADirectoryError if archivo_neuvo = ""
                os.rename(Descargas + arch, UGR + "ALG/" + arch_nuevo)     # @violation
