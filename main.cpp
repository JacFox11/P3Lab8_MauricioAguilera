#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	sqlite3 *conn;
	sqlite3_stmt *res;
	int error=0;
	int rec_count =0;
	const char *tail;
	string base="oracle-sample.db";
	
	char op='0';
	while (op!='5'){
		system("cls");
		cout<<"...:::MENU PRINCIPAL:::..."<<endl;
		cout<<"1. Listar departamentos y empleados"<<endl<<
		"2. Agregar departamento/empleado"<<endl<<
		"4. Eliminar empleado"<<endl<<
		"5. Actualizar salario de empleado"<<endl<<
		"6. Listar departamento y su respectivo departamento"<<endl<<
		"7. Salir"<<endl<<
		"Ingrese una opcion: ";
		cin>>op;
		switch (op){
			case '1':{
				char op2='0';
				while (op2!='3'){
					system("cls");
					cout<<"...:::LISTAR:::..."<<endl;
					cout<<"1. Departamentos"<<endl<<
					"2. Empleados"<<endl<<
					"3. Regresar"<<endl<<
					"Ingrese una opcion: ";
					cin>>op2;
					switch (op2){
						case '1':{
							system("cls");
							error=sqlite3_open(base.c_str(),&conn);
							error=sqlite3_prepare_v2(conn, "select * from dept",1000,&res,&tail);
							cout<<"DEPARTAMENTOS"<<endl<<endl;
							while(sqlite3_step(res) == SQLITE_ROW){
								cout<<"Deptno: "<<sqlite3_column_text(res,0)<<endl<<"Dname: "<<sqlite3_column_text(res,1)<<endl<<"Loc: "<<sqlite3_column_text(res,2)<<endl<<endl;
							}
							if (error!= SQLITE_OK){
								system("cls");
								cout<<"Ocurrio un error al listar los departamentos"<<endl;
							}
							sqlite3_close(conn);
							system("pause");
							break;
						}
						case '2':{
							system("cls");
							error=sqlite3_open(base.c_str(),&conn);
							error=sqlite3_prepare_v2(conn, "select * from emp",1000,&res,&tail);
							cout<<"EMPLEADOS"<<endl<<endl;
							while(sqlite3_step(res) == SQLITE_ROW){
								cout<<"Empno: "<<sqlite3_column_text(res,0)<<endl<<"Ename: "<<sqlite3_column_text(res,1)<<endl<<"Job: "<<sqlite3_column_text(res,2)<<endl<<"Mgr: "<<sqlite3_column_text(res,3)<<endl<<"Hiredate: "<<sqlite3_column_text(res,4)<<endl<<"Sal: "<<sqlite3_column_text(res,5)<<endl<<"Comm: "<<sqlite3_column_text(res,6)<<endl<<"Deptno: "<<sqlite3_column_text(res,7)<<endl<<endl;
							}
							if (error!= SQLITE_OK){
								system("cls");
								cout<<"Ocurrio un error al listar los empleados"<<endl;
								system("pause");
							}
							sqlite3_close(conn);
							system("pause");
							break;
						}
						case '3':{
							
							break;
						}
						default:{
							system("cls");
							cout<<"Opcion invalida, intentelo de nuevo"<<endl;
							system("pause");
							break;
						}
					}
				}
				break;
			}
			case '2':{
				char op2='0';
				while (op2!='3'){
					system("cls");
					cout<<"...:::AGREGAR:::..."<<endl;
					cout<<"1. Departamentos"<<endl<<
					"2. Empleados"<<endl<<
					"3. Regresar"<<endl<<
					"Ingrese una opcion: ";
					cin>>op2;
					switch (op2){
						case '1':{
							system("cls");
							string deptno, name, loc;
							cout<<"Deptno: ";
							cin>>deptno;
							cout<<"Dname: ";
							getline(cin, name);
							getline(cin, name);
							cout<<"Loc: ";
							getline(cin, loc);
							getline(cin, loc);
							error=sqlite3_open(base.c_str(),&conn);
							cout<<"Hola"<<endl;
							string s="insert into dept values('"+deptno+"','"+name+"','"+loc+"')";
							error=sqlite3_exec(conn, s.c_str(),0,0,0);
							cout<<"Hola"<<endl;
							if (error!= SQLITE_OK){
								system("cls");
								cout<<"Ocurrio un error al agregar el departamento"<<endl;
							}else{
								system("cls");
								cout<<"Departamento agregado exitosamente"<<endl;
							}
							sqlite3_close(conn);
							system("pause");
							break;
						}
						case '2':{
							system("cls");
							string empno, name, job, mgr, hiredate, sal, comm, deptno;
							cout<<"Empno: ";
							cin>>empno;
							cout<<"Ename: ";
							getline(cin, name);
							getline(cin, name);
							cout<<"Job: ";
							getline(cin, job);
							getline(cin, job);
							cout<<"Mgr "<<endl;
							getline(cin, mgr);
							getline(cin, mgr);
							cout<<"Hiredate (YYYY-MM-DD): ";
							getline(cin, hiredate);
							getline(cin, hiredate);
							cout<<"Sal: ";
							getline(cin, sal);
							getline(cin, sal);
							cout<<"Comm: ";
							getline(cin, comm);
							getline(cin, comm);
							cout<<"Deptno: ";
							getline(cin, deptno);
							getline(cin, deptno);
							error=sqlite3_open(base.c_str(),&conn);
							string s="insert into emp values('"+empno+"','"+name+"','"+job+"','"+mgr+"','"+hiredate+"','"+sal+"','"+comm+"','"+deptno+"')";
							error=sqlite3_exec(conn, s.c_str(),0,0,0);
							if (error!= SQLITE_OK){
								system("cls");
								cout<<"Ocurrio un error al agregar el empleado"<<endl;
							}else{
								system("cls");
								cout<<"Empleado agregado exitosamente"<<endl;
							}
							sqlite3_close(conn);
							system("pause");
							break;
						}
						case '3':{
							
							break;
						}
						default:{
							system("cls");
							cout<<"Opcion invalida, intentelo de nuevo"<<endl;
							system("pause");
							break;
						}
					}
				}
				/*string c, n, p;
				cout<<"Cuenta: ";
				cin>>c;
				cout<<"Nombre: ";
				cin>>n;
				cout<<"Profesion: ";
				cin>>p;
				string s="insert into alumnos values('"+c+"','"+n+"','"+p+"')";
				error=sqlite3_open("base1.db",&conn);
				error=sqlite3_exec(conn,s.c_str()
				,0,0,0);
				sqlite3_close(conn);*/
				break;
			}
			case '3':{
				/*string cuenta;
				cout<<"Ingrese la cuenta de persona a modificar: ";
				cin>>cuenta;
				string c, n, p;
				cout<<"nueva Cuenta: ";
				cin>>c;
				cout<<"nueva Nombre: ";
				cin>>n;
				cout<<"nueva Profesion: ";
				cin>>p;
				error=sqlite3_open("base1.db",&conn);
				error=sqlite3_exec(conn,
				"update alumnos set nombre='Pedro' where cuanta='200'"
				,0,0,0);
				sqlite3_close(conn);*/
				break;
			}
			case '4':{
				/*error=sqlite3_open("base1.db",&conn);
				error=sqlite3_exec(conn,
				"delete from alumnos where cuanta='200'"
				,0,0,0);
				sqlite3_close(conn);*/
				break;
			}
			case '5':{
				break;
			}
			default:{
				
				break;
			}
		}
	}
	
	system("pause");
	return 0;
}
