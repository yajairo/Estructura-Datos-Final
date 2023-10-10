#include <iostream>
#include <string>


#include "Software.h"
#include "Ofimatica.h"
#include "Social.h"
#include "Navegador.h"
#include "Seguridad.h"
#include "Produccion.h"
#include "Juego.h"
#include "NodoSoftware.h"
#include "Biblioteca.h"

#include "Usuario.h"
#include "UsuarioAdmin.h"
#include "UsuarioNino.h"
#include "UsuarioNormal.h"
#include "ListaUsuarios.h"


using namespace std;
// Esta función muestra la biblioteca del usuario actual
void verBibliotecaUsuario(Usuario* usuario, Biblioteca& miBiblioteca) {
    cout << "Software en la biblioteca de " << usuario->getUsuario() << ":" << endl;
    
    // Obtener la lista de software del usuario
    vector<Software*> bibliotecaUsuario = usuario->getListaSoftware();

    if (bibliotecaUsuario.empty()) {
        cout << "La biblioteca del usuario está vacía." << endl;
    } else {
        // Mostrar los software en la biblioteca del usuario
        for (const auto& software : bibliotecaUsuario) {
            cout << "- " << software->getNombre() << endl;
        }
    }
}
void menuUsuarioAdmin(UsuarioAdmin* usuario, Biblioteca& miBiblioteca,ListaUsuarios listaUsuarios) {
    while (true) {
        cout << "\nMenú Usuario Administrador:" << endl;
        cout << "1. Agregar o eliminar software de su biblioteca" << endl;
        cout << "2. Pedir eliminar un software" << endl;
        cout << "3. Ver quienes usan un software determinado ingresando el nombre" << endl;
        cout << "4. Ver el software de su biblioteca" << endl;
        cout << "5. Usar algún software por nombre (Social, Ofimática, Navegador)" << endl;
        cout << "6. Salir" << endl;

        int opcion;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Agregar o eliminar software de su biblioteca
                cout << "1. Agregar software" << endl;
                cout << "2. Eliminar software" << endl;
                cout << "3. Retroceder" << endl;

                int opcionAgregarEliminar;
                cout << "Ingrese su opción: ";
                cin >> opcionAgregarEliminar;

                switch (opcionAgregarEliminar) {
                    case 1: {
                        // Agregar software
                        string nombreSoftware;
                        cout << "Ingrese el nombre del software: ";
                        cin >> nombreSoftware;

                        Software* softwareEncontrado = miBiblioteca.buscarSoftware(nombreSoftware);

                        if (softwareEncontrado != nullptr) {
                            if (usuario->softwareEnBiblioteca(softwareEncontrado)) {
                                cout << "El software ya está en su biblioteca." << endl;
                            } else {
                                usuario->agregarSoftwareABiblioteca(softwareEncontrado);
                            }
                        } else {
                            cout << "No se encontró el software: " << nombreSoftware << endl;
                        }

                        break;
                    }
                    case 2: {
                        // Eliminar software
                        string nombreSoftware;
                        cout << "Ingrese el nombre del software a eliminar: ";
                        cin >> nombreSoftware;

                        Software* softwareEncontrado = miBiblioteca.buscarSoftware(nombreSoftware);

                        if (softwareEncontrado != nullptr) {
                            if (usuario->softwareEnBiblioteca(softwareEncontrado)) {
                                usuario->eliminarSoftware(softwareEncontrado->getNombre());
                                cout << "Software eliminado de su biblioteca." << endl;
                            } else {
                                cout << "El software no está en su biblioteca." << endl;
                            }
                        } else {
                            cout << "No se encontró el software: " << nombreSoftware << endl;
                        }

                        break;
                    }
                    case 3:
                        // Retroceder
                        break;
                    default:
                        cout << "Opción no válida." << endl;
                        break;
                }
                break;
            }
            case 2:{
                // Pedir eliminar un software con confirmación
                string nombreSoftware;
                cout << "Ingrese el nombre del software a eliminar: ";
                cin >> nombreSoftware;

                // Llamar a la función de eliminación con confirmación
                miBiblioteca.eliminarSoftwareConConfirmacion(nombreSoftware, listaUsuarios);
                break;
            }
            case 3:{
            // Lógica para ver quiénes usan un software determinado
            string nombreSoftware;
            cout << "Ingrese el nombre del software para ver quiénes lo usan: ";
            cin >> nombreSoftware;

            miBiblioteca.verUsuariosDelSoftware(nombreSoftware, listaUsuarios);
            break;
        }
            case 4:
                verBibliotecaUsuario(usuario, miBiblioteca);
                break;

case 5: {
    // Lógica para usar algún software por nombre (Social, Ofimática, Navegador)
    string nombreSoftware;
    cout << "Ingrese el nombre del software que desea usar: ";
    cin >> nombreSoftware;

    // Obtener la instancia del usuario actual
    Usuario* usuarioActual = usuario;

    // Verificar si el software existe en la biblioteca del usuario actual
    Software* softwareEncontrado = usuarioActual->buscarSoftwareEnBiblioteca(nombreSoftware);

    if (softwareEncontrado != nullptr) {
        // Verificar el tipo de software
        if (dynamic_cast<Social*>(softwareEncontrado) != nullptr) {
            // Es un software de tipo Social
            Social* softwareSocial = dynamic_cast<Social*>(softwareEncontrado);
            cout << "El software es de tipo Social." << endl;
            int opcionAgregarEliminar;

            bool continuarEnBucle = true;

            while (continuarEnBucle){
            cout << "Opciones:" << endl;
            cout << "1. Agregar amigo" << endl;
            cout << "2. Eliminar amigo" << endl;
            cout << "3. Retroceder" << endl;
            cout << "4. Ver lista de amigos" << endl;
            cout << "Ingrese el número de la opción: ";
            cin >> opcionAgregarEliminar;

        switch (opcionAgregarEliminar) {
            case 1: {
                // Agregar amigo
                string nombreAmigo;
                cout << "Ingrese el nombre del amigo que desea agregar: ";
                cin >> nombreAmigo;

                // Verificar si el amigo existe en la lista de usuarios
                Usuario* amigoEncontrado = listaUsuarios.buscarUsuario(nombreAmigo);
                if (amigoEncontrado != nullptr) {
                    // Lógica para agregar amigo al software Social
                    softwareSocial->agregarNombreAmigo(nombreAmigo);
                } else {
                    cout << "El amigo no existe en la lista de usuarios." << endl;
                }
                break;
            }
            case 2: {
                // Eliminar amigo
                string nombreAmigo;
                cout << "Ingrese el nombre del amigo que desea eliminar: ";
                cin >> nombreAmigo;

                // Verificar si el amigo existe en la lista de usuarios
                Usuario* amigoEncontrado = listaUsuarios.buscarUsuario(nombreAmigo);
                if (amigoEncontrado != nullptr) {
                    // Lógica para eliminar amigo del software Social
                    softwareSocial->eliminarNombreAmigo(nombreAmigo);
                    cout << "Amigo eliminado del software." << endl;
                } else {
                    cout << "El amigo no existe en la lista de usuarios." << endl;
                }
                break;
            }
            case 3:
            continuarEnBucle = false;
            break;

            case 4:
                // Ver lista de amigos
                softwareSocial->verListaAmigos();
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }
        } else if (dynamic_cast<Ofimatica*>(softwareEncontrado) != nullptr) {
            // Es un software de tipo Ofimática
            Ofimatica* softwareOfimatica = dynamic_cast<Ofimatica*>(softwareEncontrado);

            // Dar opciones específicas para Ofimática
            cout << "1. Agregar archivo" << endl;
            cout << "2. Ver archivos guardados" << endl;
            cout << "3. Retroceder" << endl;

            int opcionOfimatica;
            cout << "Ingrese su opción: ";
            cin >> opcionOfimatica;

            switch (opcionOfimatica) {
                case 1: {
                    // Agregar archivo
                    string nombreArchivo;
                    cout << "Ingrese el nombre del archivo que desea agregar: ";
                    cin >> nombreArchivo;
                    softwareOfimatica->agregarArchivo(nombreArchivo);
                    cout << "Archivo agregado al software de Ofimática." << endl;
                    break;
                }
                case 2: {
                    // Ver archivos guardados
                    softwareOfimatica->imprimirArchivos();
                    break;
                }
                case 3:
                    // Retroceder
                    break;
                default:
                    cout << "Opción no válida." << endl;
                    break;
            }

            // Lógica específica para el software de Ofimática

        } else if (dynamic_cast<Navegador*>(softwareEncontrado) != nullptr) {
            // Software de tipo Navegador
            Navegador* navegador = dynamic_cast<Navegador*>(softwareEncontrado);
            if (navegador != nullptr) {
                cout << "El software es de tipo Navegador." << endl;

                // Dar opciones para agregar páginas visitadas, ver páginas visitadas o borrar historial de navegación
                cout << "1. Agregar página visitada" << endl;
                cout << "2. Ver páginas visitadas" << endl;
                cout << "3. Borrar historial de navegación" << endl;  // Nueva opción
                cout << "4. Retroceder" << endl;

                int opcionNavegador;
                cout << "Ingrese su opción: ";
                cin >> opcionNavegador;

                switch (opcionNavegador) {
                    case 1: {
                        // Agregar página visitada
                        string paginaVisitada;
                        cout << "Ingrese la página visitada: ";
                        cin >> paginaVisitada;

                        navegador->agregarPaginaVisitada(paginaVisitada);
                        cout << "Página visitada agregada al software." << endl;
                        break;
                    }
                    case 2: {
                        // Ver páginas visitadas
                        navegador->verPaginasVisitadas();
                        break;
                    }
                    case 3: {
                        // Borrar historial de navegación
                        navegador->borrarHistorialNavegacion();
                        break;
                    }
                    case 4:
                        // Retroceder
                        break;
                    default:
                        cout << "Opción no válida." << endl;
                        break;
                }
            }
        } else {
            cout << "El software no es de tipo Ofimática ni Navegador." << endl;
        }
    } else {
        cout << "No se encontró el software en su biblioteca: " << nombreSoftware << endl;
    }
    break;
}


            case 6:
                cout << "Saliendo del menú de Usuario Administrador." << endl;
                return;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    }
}


void menuUsuarioNino(UsuarioNino* usuario, Biblioteca& miBiblioteca,ListaUsuarios& listaUsuarios) {
    while (true) {
        cout << "\nMenú Usuario Niño:" << endl;
        cout << "1. Agregar o eliminar software de su biblioteca" << endl;
        cout << "2. Pedir eliminar un software" << endl;
        cout << "3. Ver el software de su biblioteca" << endl;
        cout << "4. Usar algún software por nombre (Social, Ofimática, Navegador)" << endl;
        cout << "5. Salir" << endl;

        int opcion;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Agregar o eliminar software de su biblioteca
                cout << "1. Agregar software" << endl;
                cout << "2. Eliminar software" << endl;
                cout << "3. Retroceder" << endl;

                int opcionAgregarEliminar;
                cout << "Ingrese su opción: ";
                cin >> opcionAgregarEliminar;

                switch (opcionAgregarEliminar) {
                    case 1: {
                        // Agregar software
                        string nombreSoftware;
                        cout << "Ingrese el nombre del software: ";
                        cin >> nombreSoftware;

                        Software* softwareEncontrado = miBiblioteca.buscarSoftware(nombreSoftware);

                        if (softwareEncontrado != nullptr) {
                            if (usuario->softwareEnBiblioteca(softwareEncontrado)) {
                                cout << "El software ya está en su biblioteca." << endl;
                            } else {
                                usuario->agregarSoftwareABiblioteca(softwareEncontrado);
                            }
                        } else {
                            cout << "No se encontró el software: " << nombreSoftware << endl;
                        }

                        break;
                    }
                    case 2: {
                        // Eliminar software
                        string nombreSoftware;
                        cout << "Ingrese el nombre del software a eliminar: ";
                        cin >> nombreSoftware;

                        Software* softwareEncontrado = miBiblioteca.buscarSoftware(nombreSoftware);

                        if (softwareEncontrado != nullptr) {
                            if (usuario->softwareEnBiblioteca(softwareEncontrado)) {
                                usuario->eliminarSoftware(softwareEncontrado->getNombre());
                                cout << "Software eliminado de su biblioteca." << endl;
                            } else {
                                cout << "El software no está en su biblioteca." << endl;
                            }
                        } else {
                            cout << "No se encontró el software: " << nombreSoftware << endl;
                        }

                        break;
                    }
                    case 3:
                        // Retroceder
                        break;
                    default:
                        cout << "Opción no válida." << endl;
                        break;
                }
                break;
            case 2:{
                // Pedir eliminar un software con confirmación
                string nombreSoftware;
                cout << "Ingrese el nombre del software a eliminar: ";
                cin >> nombreSoftware;

                // Llamar a la función de eliminación con confirmación
                miBiblioteca.eliminarSoftwareConConfirmacion(nombreSoftware, listaUsuarios);
                break;
            }
            case 3:
                verBibliotecaUsuario(usuario, miBiblioteca);
                break;
            case 4:
                 {
    // Lógica para usar algún software por nombre (Social, Ofimática, Navegador)
    string nombreSoftware;
    cout << "Ingrese el nombre del software que desea usar: ";
    cin >> nombreSoftware;

    // Obtener la instancia del usuario actual
    Usuario* usuarioActual = usuario;

    // Verificar si el software existe en la biblioteca del usuario actual
    Software* softwareEncontrado = usuarioActual->buscarSoftwareEnBiblioteca(nombreSoftware);

    if (softwareEncontrado != nullptr) {
        // Verificar el tipo de software
        if (dynamic_cast<Social*>(softwareEncontrado) != nullptr) {
            // Es un software de tipo Social
            Social* softwareSocial = dynamic_cast<Social*>(softwareEncontrado);
            cout << "El software es de tipo Social." << endl;

            bool continuarEnBucle = true;
            while (continuarEnBucle){
            cout << "Opciones:" << endl;
            cout << "1. Agregar amigo" << endl;
            cout << "2. Eliminar amigo" << endl;
            cout << "3. Retroceder" << endl;
            cout << "4. Ver lista de amigos" << endl;
            cout << "Ingrese el número de la opción: ";
            cin >> opcionAgregarEliminar;

              switch (opcionAgregarEliminar) {
                case 1: {
                    // Agregar amigo menor de 18
                    string nombreAmigo;
                    cout << "Ingrese el nombre del amigo menor de 18 que desea agregar: ";
                    cin >> nombreAmigo;

                    // Verificar si el amigo existe en la lista de usuarios y es menor de 18
                    Usuario* amigoEncontrado = listaUsuarios.buscarUsuario(nombreAmigo);
                    if (amigoEncontrado != nullptr && amigoEncontrado->getEdad() < 18) {
                        // Lógica para agregar amigo al software Social
                        softwareSocial->agregarNombreAmigo(nombreAmigo);
                    } else {
                        cout << "El amigo no existe en la lista de usuarios o no es menor de 18." << endl;
                    }
                    break;
                }
                case 2: {
                    // Eliminar amigo
                    string nombreAmigo;
                    cout << "Ingrese el nombre del amigo que desea eliminar: ";
                    cin >> nombreAmigo;

                    // Verificar si el amigo existe en la lista de usuarios
                    Usuario* amigoEncontrado = listaUsuarios.buscarUsuario(nombreAmigo);
                    if (amigoEncontrado != nullptr) {
                        // Lógica para eliminar amigo del software Social
                        softwareSocial->eliminarNombreAmigo(nombreAmigo);
                        cout << "Amigo eliminado del software." << endl;
                    } else {
                        cout << "El amigo no existe en la lista de usuarios." << endl;
                    }
                    break;
                }
                case 3:
                continuarEnBucle = false;
                break;
                case 4:
                // Ver lista de amigos
                softwareSocial->verListaAmigos();
                break;
                default:
                    cout << "Opción no válida." << endl;
                    break;
            }
        }
        } else if (dynamic_cast<Ofimatica*>(softwareEncontrado) != nullptr) {
            // Es un software de tipo Ofimática
            Ofimatica* softwareOfimatica = dynamic_cast<Ofimatica*>(softwareEncontrado);

            // Dar opciones específicas para Ofimática
            cout << "1. Agregar archivo" << endl;
            cout << "2. Ver archivos guardados" << endl;
            cout << "3. Retroceder" << endl;

            int opcionOfimatica;
            cout << "Ingrese su opción: ";
            cin >> opcionOfimatica;

            switch (opcionOfimatica) {
                case 1: {
                    // Agregar archivo
                    string nombreArchivo;
                    cout << "Ingrese el nombre del archivo que desea agregar: ";
                    cin >> nombreArchivo;
                    softwareOfimatica->agregarArchivo(nombreArchivo);
                    cout << "Archivo agregado al software de Ofimática." << endl;
                    break;
                }
                case 2: {
                    // Ver archivos guardados
                    softwareOfimatica->imprimirArchivos();
                    break;
                }
                case 3:
                    // Retroceder
                    break;
                default:
                    cout << "Opción no válida." << endl;
                    break;
            }

            // Lógica específica para el software de Ofimática

        } else if (dynamic_cast<Navegador*>(softwareEncontrado) != nullptr) {
            // Software de tipo Navegador
            Navegador* navegador = dynamic_cast<Navegador*>(softwareEncontrado);
            if (navegador != nullptr) {
                cout << "El software es de tipo Navegador." << endl;

                // Dar opciones para agregar páginas visitadas, ver páginas visitadas o borrar historial de navegación
                cout << "1. Agregar página visitada" << endl;
                cout << "2. Ver páginas visitadas" << endl;
                cout << "3. Borrar historial de navegación" << endl;  // Nueva opción
                cout << "4. Retroceder" << endl;

                int opcionNavegador;
                cout << "Ingrese su opción: ";
                cin >> opcionNavegador;

                switch (opcionNavegador) {
                    case 1: {
                        // Agregar página visitada
                        string paginaVisitada;
                        cout << "Ingrese la página visitada: ";
                        cin >> paginaVisitada;

                        navegador->agregarPaginaVisitada(paginaVisitada);
                        cout << "Página visitada agregada al software." << endl;
                        break;
                    }
                    case 2: {
                        // Ver páginas visitadas
                        navegador->verPaginasVisitadas();
                        break;
                    }
                    case 3: {
                        // Borrar historial de navegación
                        navegador->borrarHistorialNavegacion();
                        break;
                    }
                    case 4:
                        // Retroceder
                        break;
                    default:
                        cout << "Opción no válida." << endl;
                        break;
                }
            }
        } else {
            cout << "El software no es de tipo Ofimática ni Navegador." << endl;
        }
    } else {
        cout << "No se encontró el software en su biblioteca: " << nombreSoftware << endl;
    }
    break;
}
            case 5:
                cout << "Saliendo del menú de Usuario Niño." << endl;
                return;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    }
}

void menuUsuarioNormal(UsuarioNormal* usuario, Biblioteca& miBiblioteca,ListaUsuarios& listaUsuarios) {
    while (true) {
        cout << "\nMenú Usuario Normal:" << endl;
        cout << "1. Agregar o eliminar software de su biblioteca" << endl;
        cout << "2. Pedir eliminar un software" << endl;
        cout << "3. Ver el software de su biblioteca" << endl;
        cout << "4. Usar algún software por nombre (Social, Ofimática, Navegador)" << endl;
        cout << "5. Salir" << endl;

        int opcion;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Agregar o eliminar software de su biblioteca
                cout << "1. Agregar software" << endl;
                cout << "2. Eliminar software" << endl;
                cout << "3. Retroceder" << endl;

                int opcionAgregarEliminar;
                cout << "Ingrese su opción: ";
                cin >> opcionAgregarEliminar;

                switch (opcionAgregarEliminar) {
                    case 1: {
                        // Agregar software
                        string nombreSoftware;
                        cout << "Ingrese el nombre del software: ";
                        cin >> nombreSoftware;

                        Software* softwareEncontrado = miBiblioteca.buscarSoftware(nombreSoftware);

                        if (softwareEncontrado != nullptr) {
                            if (usuario->softwareEnBiblioteca(softwareEncontrado)) {
                                cout << "El software ya está en su biblioteca." << endl;
                            } else {
                                usuario->agregarSoftwareABiblioteca(softwareEncontrado);
                            }
                        } else {
                            cout << "No se encontró el software: " << nombreSoftware << endl;
                        }

                        break;
                    }
                    case 2: {
                        // Eliminar software
                        string nombreSoftware;
                        cout << "Ingrese el nombre del software a eliminar: ";
                        cin >> nombreSoftware;

                        Software* softwareEncontrado = miBiblioteca.buscarSoftware(nombreSoftware);

                        if (softwareEncontrado != nullptr) {
                            if (usuario->softwareEnBiblioteca(softwareEncontrado)) {
                                usuario->eliminarSoftware(softwareEncontrado->getNombre());
                                cout << "Software eliminado de su biblioteca." << endl;
                            } else {
                                cout << "El software no está en su biblioteca." << endl;
                            }
                        } else {
                            cout << "No se encontró el software: " << nombreSoftware << endl;
                        }

                        break;
                    }
                    case 3:
                        // Retroceder
                        break;
                    default:
                        cout << "Opción no válida." << endl;
                        break;
                }
                break;
            case 2:{
                // Pedir eliminar un software con confirmación
                string nombreSoftware;
                cout << "Ingrese el nombre del software a eliminar: ";
                cin >> nombreSoftware;

                // Llamar a la función de eliminación con confirmación
                miBiblioteca.eliminarSoftwareConConfirmacion(nombreSoftware, listaUsuarios);
                break;
            }
            case 3:
                 verBibliotecaUsuario(usuario, miBiblioteca);
                break;
                
            case 4:{
    // Lógica para usar algún software por nombre (Social, Ofimática, Navegador)
    string nombreSoftware;
    cout << "Ingrese el nombre del software que desea usar: ";
    cin >> nombreSoftware;

    // Obtener la instancia del usuario actual
    Usuario* usuarioActual = usuario;

    // Verificar si el software existe en la biblioteca del usuario actual
    Software* softwareEncontrado = usuarioActual->buscarSoftwareEnBiblioteca(nombreSoftware);

    if (softwareEncontrado != nullptr) {
        // Verificar el tipo de software
        if (dynamic_cast<Social*>(softwareEncontrado) != nullptr) {
            // Es un software de tipo Social
            Social* softwareSocial = dynamic_cast<Social*>(softwareEncontrado);
            cout << "El software es de tipo Social." << endl;
            bool continuarEnBucle = true;
            int opcionAgregarEliminar;

    while (continuarEnBucle) {
        cout << "Opciones:" << endl;
        cout << "1. Agregar amigo" << endl;
        cout << "2. Eliminar amigo" << endl;
        cout << "3. Retroceder" << endl;
        cout << "4. Ver lista de amigos" << endl;
        cout << "Ingrese el número de la opción: ";
        cin >> opcionAgregarEliminar;

        switch (opcionAgregarEliminar) {
            case 1: {
                // Agregar amigo
                string nombreAmigo;
                cout << "Ingrese el nombre del amigo que desea agregar: ";
                cin >> nombreAmigo;

                // Verificar si el amigo existe en la lista de usuarios
                Usuario* amigoEncontrado = listaUsuarios.buscarUsuario(nombreAmigo);
                if (amigoEncontrado != nullptr) {
                    // Lógica para agregar amigo al software Social
                    softwareSocial->agregarNombreAmigo(nombreAmigo);
                } else {
                    cout << "El amigo no existe en la lista de usuarios." << endl;
                }
                break;
            }
            case 2: {
                // Eliminar amigo
                string nombreAmigo;
                cout << "Ingrese el nombre del amigo que desea eliminar: ";
                cin >> nombreAmigo;

                // Verificar si el amigo existe en la lista de usuarios
                Usuario* amigoEncontrado = listaUsuarios.buscarUsuario(nombreAmigo);
                if (amigoEncontrado != nullptr) {
                    // Lógica para eliminar amigo del software Social
                    softwareSocial->eliminarNombreAmigo(nombreAmigo);
                    cout << "Amigo eliminado del software." << endl;
                } else {
                    cout << "El amigo no existe en la lista de usuarios." << endl;
                }
                break;
            }
            case 3:
                // Retroceder
                continuarEnBucle = false;
                break;
;
            case 4:
                // Ver lista de amigos
                softwareSocial->verListaAmigos();
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }
        } else if (dynamic_cast<Ofimatica*>(softwareEncontrado) != nullptr) {
            // Es un software de tipo Ofimática
            Ofimatica* softwareOfimatica = dynamic_cast<Ofimatica*>(softwareEncontrado);

            // Dar opciones específicas para Ofimática
            cout << "1. Agregar archivo" << endl;
            cout << "2. Ver archivos guardados" << endl;
            cout << "3. Retroceder" << endl;

            int opcionOfimatica;
            cout << "Ingrese su opción: ";
            cin >> opcionOfimatica;

            switch (opcionOfimatica) {
                case 1: {
                    // Agregar archivo
                    string nombreArchivo;
                    cout << "Ingrese el nombre del archivo que desea agregar: ";
                    cin >> nombreArchivo;
                    softwareOfimatica->agregarArchivo(nombreArchivo);
                    cout << "Archivo agregado al software de Ofimática." << endl;
                    break;
                }
                case 2: {
                    // Ver archivos guardados
                    softwareOfimatica->imprimirArchivos();
                    break;
                }
                case 3:
                    // Retroceder
                    break;
                default:
                    cout << "Opción no válida." << endl;
                    break;
            }

            // Lógica específica para el software de Ofimática

        } else if (dynamic_cast<Navegador*>(softwareEncontrado) != nullptr) {
            // Software de tipo Navegador
            Navegador* navegador = dynamic_cast<Navegador*>(softwareEncontrado);
            if (navegador != nullptr) {
                cout << "El software es de tipo Navegador." << endl;

                // Dar opciones para agregar páginas visitadas, ver páginas visitadas o borrar historial de navegación
                cout << "1. Agregar página visitada" << endl;
                cout << "2. Ver páginas visitadas" << endl;
                cout << "3. Borrar historial de navegación" << endl;  // Nueva opción
                cout << "4. Retroceder" << endl;

                int opcionNavegador;
                cout << "Ingrese su opción: ";
                cin >> opcionNavegador;

                switch (opcionNavegador) {
                    case 1: {
                        // Agregar página visitada
                        string paginaVisitada;
                        cout << "Ingrese la página visitada: ";
                        cin >> paginaVisitada;

                        navegador->agregarPaginaVisitada(paginaVisitada);
                        cout << "Página visitada agregada al software." << endl;
                        break;
                    }
                    case 2: {
                        // Ver páginas visitadas
                        navegador->verPaginasVisitadas();
                        break;
                    }
                    case 3: {
                        // Borrar historial de navegación
                        navegador->borrarHistorialNavegacion();
                        break;
                    }
                    case 4:
                        // Retroceder
                        break;
                    default:
                        cout << "Opción no válida." << endl;
                        break;
                }
            }
        } else {
            cout << "El software no es de tipo Ofimática ni Navegador." << endl;
        }
    } else {
        cout << "No se encontró el software en su biblioteca: " << nombreSoftware << endl;
    }
    break;
}
            case 5:
                cout << "Saliendo del menú de Usuario Normal." << endl;
                return;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    }
}
int main() {
    srand(time(0));

    ListaUsuarios lista;

    // Crear 2 administradores
    //UsuarioAdmin* admin1 = new UsuarioAdmin("admin1", "admin123", 30, "admin1@email.com");
    //UsuarioAdmin* admin2 = new UsuarioAdmin("admin2", "admin456", 35, "admin2@email.com");

    lista.agregarUsuario(new UsuarioAdmin("admin1", "admin123", 30, "admin1@email.com"));
    lista.agregarUsuario(new UsuarioAdmin("admin2", "admin456", 35, "admin2@email.com"));

    // Agregar 5 niños
    lista.agregarUsuario(new UsuarioNino("nino1", "nino123", 8));
    lista.agregarUsuario(new UsuarioNino("nino2", "nino456", 6));
    lista.agregarUsuario(new UsuarioNino("nino3", "nino789", 9));
    lista.agregarUsuario(new UsuarioNino("nino4", "ninoabc", 7));
    lista.agregarUsuario(new UsuarioNino("nino5", "ninoxyz", 5));

    // Agregar 11 usuarios normales
    lista.agregarUsuario(new UsuarioNormal("normal1", "normal123", 25, "normal1@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal2", "normal456", 22, "normal2@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal3", "normal789", 28, "normal3@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal4", "normalabc", 30, "normal4@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal5", "normalxyz", 21, "normal5@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal6", "normal123", 29, "normal6@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal7", "normal456", 27, "normal7@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal8", "normal789", 24, "normal8@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal9", "normalabc", 26, "normal9@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal10", "normalxyz", 23, "normal10@email.com"));
    lista.agregarUsuario(new UsuarioNormal("normal11", "normal123", 31, "normal11@email.com"));

    // Crear una biblioteca
    Biblioteca miBiblioteca;

    // Poblar la biblioteca con juegos (20 juegos en total, 2 de cada género)
    for (int i = 1; i <= 20; i++) {
        string nombreJuego = "Juego" + to_string(i);
        string developer = "Desarrollador" + to_string(i);
        int clasificacion = (i <= 10) ? 18 : 12;  // 10 juegos para 18+ y 10 para 12+
        int precio = 49 + i;  // Precio ficticio

        // Crear instancia de Juego
        Juego* juego = new Juego(nombreJuego, developer, clasificacion, precio, "Aventura");

        // Agregar el juego a la biblioteca
        miBiblioteca.agregarSoftware(juego);
    }

    // Poblar la biblioteca con software de ofimática (5 software)
    for (int i = 1; i <= 5; i++) {
        string nombreOfimatica = "Ofimatica" + to_string(i);
        string developer = "Desarrollador" + to_string(i);
        int clasificacion = 0;  // Clasificación no relevante para software de ofimática
        int precio = 29 + i;  // Precio ficticio

        // Crear instancia de Ofimatica
        Ofimatica* ofimatica = new Ofimatica(nombreOfimatica, developer, clasificacion, precio, "Ofimatica");

        // Agregar el software de ofimática a la biblioteca
        miBiblioteca.agregarSoftware(ofimatica);
    }

    // Poblar la biblioteca con software de producción (4 software)
    for (int i = 1; i <= 4; i++) {
        string nombreProduccion = "Produccion" + to_string(i);
        string developer = "Desarrollador" + to_string(i);
        int clasificacion = 18;  // Todos los software de producción son 18+
        int precio = 79 + i;  // Precio ficticio

        // Crear instancia de Produccion
        Produccion* produccion = new Produccion(nombreProduccion, developer, clasificacion, precio, "Produccion");

        // Agregar el software de producción a la biblioteca
        miBiblioteca.agregarSoftware(produccion);
    }

    // Poblar la biblioteca con navegadores (2 navegadores)
    for (int i = 1; i <= 2; i++) {
        string nombreNavegador = "Navegador" + to_string(i);
        string developer = "Desarrollador" + to_string(i);
        int clasificacion = 0;  // Clasificación no relevante para navegadores
        int precio = 0;  // Precio gratuito

        // Crear instancia de Navegador
        Navegador* navegador = new Navegador(nombreNavegador, developer, clasificacion, precio, "Navegador");

        // Agregar el navegador a la biblioteca
        miBiblioteca.agregarSoftware(navegador);
    }

    // Poblar la biblioteca con software de seguridad (6 software, 1 de cada tipo)
    for (int i = 1; i <= 6; i++) {
        string nombreSeguridad = "Seguridad" + to_string(i);
        string developer = "Desarrollador" + to_string(i);
        int clasificacion = 0;  // Clasificación no relevante para software de seguridad
        int precio = 49 + i;  // Precio ficticio
        string tipo;

        switch (i) {
            case 1:
                tipo = "Antivirus";
                break;
            case 2:
                tipo = "Firewall";
                break;
            case 3:
                tipo = "Antispyware";
                break;
            case 4:
                tipo = "Antimalware";
                break;
            case 5:
                tipo = "Seguridad de Red";
                break;
            case 6:
                tipo = "Control Parental";
                break;
        }

        // Crear instancia de Seguridad
        Seguridad* seguridad = new Seguridad(nombreSeguridad, developer, clasificacion, precio, tipo);

        // Agregar el software de seguridad a la biblioteca
        miBiblioteca.agregarSoftware(seguridad);
    }

    // Poblar la biblioteca con software social (2 software, al menos 1 es 18+)
    // Crear objetos Social
Social* socialMayores18 = new Social("SocialMayores18", "DesarrolladorSocial", 18, 0);
Social* socialCualquierEdad = new Social("SocialCualquierEdad", "DesarrolladorSocial", 0, 0);
miBiblioteca.agregarSoftware(socialMayores18);
miBiblioteca.agregarSoftware(socialCualquierEdad);


// Iterar sobre los usuarios y agregar objetos Social según las restricciones de edad
// Obtén el inicio de la lista
NodoUsuario* temp = lista.obtenerInicio();

// Itera a través de la lista de usuarios
while (temp != nullptr) {
    Usuario* usuario = temp->getUsuario();

    if (usuario->getEdad() >= 18) {
        // Asignar el objeto Social a usuarios mayores de 18
        usuario->agregarSoftwareABiblioteca(socialMayores18);

        // Agregar dos amigos aleatorios mayores de 18 al objeto Social
        for (int i = 0; i < 2; ++i) {
            Usuario* amigo = NULL;

            // Obtener un amigo aleatorio diferente del usuario actual
            do {
                amigo = lista.obtenerUsuarioAleatorioMayorDeEdad();
            } while (amigo != nullptr && amigo == usuario);

            if (amigo != nullptr) {
                socialMayores18->agregarNombreAmigo(amigo->getUsuario());
            }
        }
    } else {
        // Asignar el objeto Social a usuarios menores de 18
        usuario->agregarSoftwareABiblioteca(socialCualquierEdad);

        // Agregar dos amigos aleatorios menores de 18 al objeto Social
        for (int i = 0; i < 2; ++i) {
            Usuario* amigo = NULL;

            // Obtener un amigo aleatorio diferente del usuario actual
            do {
                amigo = lista.obtenerUsuarioAleatorioMenorDeEdad();
            } while (amigo != nullptr && amigo == usuario);

            if (amigo != nullptr) {
                socialCualquierEdad->agregarNombreAmigo(amigo->getUsuario());
            }
        }
    }

    // Mover al siguiente nodo
    temp = temp->getSiguiente();
}


    
    // Mostrar el contenido de la biblioteca
    miBiblioteca.mostrarSoftware();
    // Mostrar la lista de usuarios
    string usuario, contrasena;

    while (true) {
        cout << "Ingrese su nombre de usuario (o 'exit' para salir): ";
        cin >> usuario;

        if (usuario == "exit") {
            break;
        }

        cout << "Ingrese su contraseña: ";
        cin >> contrasena;

        Usuario* usuarioEncontrado = lista.buscarUsuario(usuario, contrasena);

        if (usuarioEncontrado != nullptr) {
        string tipoUsuario = usuarioEncontrado->obtenerTipo();

        if (tipoUsuario == "UsuarioAdmin") {
            cout << "Bienvenido, Administrador." << endl;
            menuUsuarioAdmin(dynamic_cast<UsuarioAdmin*>(usuarioEncontrado),miBiblioteca,lista);
        } else if (tipoUsuario == "UsuarioNino") {
            cout << "Bienvenido, Usuario Niño." << endl;
            menuUsuarioNino(dynamic_cast<UsuarioNino*>(usuarioEncontrado),miBiblioteca,lista);
        } else if (tipoUsuario == "UsuarioNormal") {
            cout << "Bienvenido, Usuario Normal." << endl;
            menuUsuarioNormal(dynamic_cast<UsuarioNormal*>(usuarioEncontrado),miBiblioteca,lista);
        }

        // ... (puedes agregar más lógica específica para cada tipo de usuario)
    } else {
        cout << "Usuario o contraseña incorrectos. Intente de nuevo." << endl;
    }
    }

    cout << "Gracias por usar el sistema. ¡Hasta luego!" << endl;

    return 0;
    //aaaa
    
}

