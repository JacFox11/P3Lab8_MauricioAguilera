#include <iostream>
#include <string>
#include <bits/stdc++.h>
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
	while (op!='7'){
		system("cls");
		cout<<"...:::MENU PRINCIPAL:::..."<<endl;
		cout<<"1. Listar departamentos y empleados"<<endl<<
		"2. Agregar departamento/empleado"<<endl<<
		"3. Eliminar empleado"<<endl<<
		"4. Listar Jefe con sus empleados respectivos"<<endl<<
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
								cout<<setw(8)<<"Deptno: "<<sqlite3_column_text(res,0)<<endl<<setw(8)<<"Dname: "<<sqlite3_column_text(res,1)<<endl<<setw(8)<<"Loc: "<<sqlite3_column_text(res,2)<<endl<<endl;
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
								cout<<setw(10)<<"Empno: "<<sqlite3_column_text(res,0)<<endl<<setw(10)<<"Ename: "<<sqlite3_column_text(res,1)<<endl<<setw(10)<<"Job: "<<sqlite3_column_text(res,2)<<endl<<setw(10)<<"Mgr: "<<sqlite3_column_text(res,3)<<endl<<setw(10)<<"Hiredate: "<<sqlite3_column_text(res,4)<<endl<<setw(10)<<"Sal: "<<sqlite3_column_text(res,5)<<endl<<setw(10)<<"Comm: "<<sqlite3_column_text(res,6)<<endl<<setw(10)<<"Deptno: "<<sqlite3_column_text(res,7)<<endl<<endl;
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
							cout<<"Mgr: ";
							getline(cin, mgr);
							cout<<"Hiredate (YYYY-MM-DD): ";
							getline(cin, hiredate);
							cout<<"Sal: ";
							getline(cin, sal);
							cout<<"Comm: ";
							getline(cin, comm);
							cout<<"Deptno: ";
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
				break;
			}
			case '3':{
				system("cls");
				error=sqlite3_open(base.c_str(),&conn);
				cout<<"...:::ELIMINAR EMPLEADO:::..."<<endl;
				error=sqlite3_prepare_v2(conn, "select emp.empno,emp.ename from emp",1000,&res,&tail);
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<sqlite3_column_text(res,0)<<", "<<sqlite3_column_text(res,1)<<endl;
				}
				cout<<endl;
				string empno;
				cout<<"Empno del empleado a eliminar: ";
				cin>>empno;
				string s="delete from emp where empno='"+empno+"'";
				error=sqlite3_exec(conn,s.c_str(),0,0,0);
				sqlite3_close(conn);
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
				system("cls");
				error=sqlite3_open(base.c_str(),&conn);
				cout<<"...:::LISTAR JEFE:::..."<<endl;
				error=sqlite3_prepare_v2(conn, "select emp.empno,emp.ename from emp",1000,&res,&tail);
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<sqlite3_column_text(res,0)<<", "<<sqlite3_column_text(res,1)<<endl;
				}
				cout<<endl;
				string empno;
				cout<<"Empno del empleado a listar: ";
				cin>>empno;
				system("cls");
				string s="select * from emp where empno='"+empno+"'";
				error=sqlite3_prepare_v2(conn, s.c_str(),1000,&res,&tail);
				cout<<"JEFE:"<<endl<<endl;
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<setw(10)<<"Empno: "<<sqlite3_column_text(res,0)<<endl<<setw(10)<<"Ename: "<<sqlite3_column_text(res,1)<<endl<<setw(10)<<"Job: "<<sqlite3_column_text(res,2)<<endl<<setw(10)<<"Mgr: "<<sqlite3_column_text(res,3)<<endl<<setw(10)<<"Hiredate: "<<sqlite3_column_text(res,4)<<endl<<setw(10)<<"Sal: "<<sqlite3_column_text(res,5)<<endl<<setw(10)<<"Comm: "<<sqlite3_column_text(res,6)<<endl<<setw(10)<<"Deptno: "<<sqlite3_column_text(res,7)<<endl<<endl;
				}
				cout<<endl;
				s="select * from emp where mgr='"+empno+"'";
				error=sqlite3_prepare_v2(conn, s.c_str(),1000,&res,&tail);
				cout<<"EMPLEADOS:"<<endl<<endl;
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<setw(10)<<"Empno: "<<sqlite3_column_text(res,0)<<endl<<setw(10)<<"Ename: "<<sqlite3_column_text(res,1)<<endl<<setw(10)<<"Job: "<<sqlite3_column_text(res,2)<<endl<<setw(10)<<"Mgr: "<<sqlite3_column_text(res,3)<<endl<<setw(10)<<"Hiredate: "<<sqlite3_column_text(res,4)<<endl<<setw(10)<<"Sal: "<<sqlite3_column_text(res,5)<<endl<<setw(10)<<"Comm: "<<sqlite3_column_text(res,6)<<endl<<setw(10)<<"Deptno: "<<sqlite3_column_text(res,7)<<endl<<endl;
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
			case '5':{
				system("cls");
				int actual;
				int c=0;
				int nuevo=0;
				error=sqlite3_open(base.c_str(),&conn);
				cout<<"...:::ACTUALIZAR JEFE:::..."<<endl;
				error=sqlite3_prepare_v2(conn, "select emp.empno,emp.ename from emp",1000,&res,&tail);
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<sqlite3_column_text(res,0)<<", "<<sqlite3_column_text(res,1)<<endl;
				}
				cout<<endl;
				string empno;
				cout<<"Empno del empleado a actualizar: ";
				cin>>empno;
				system("cls");
				string s="select emp.sal from emp where empno='"+empno+"'";
				error=sqlite3_prepare_v2(conn, s.c_str(),1000,&res,&tail);
				while(sqlite3_step(res) == SQLITE_ROW){
					actual=atoi(reinterpret_cast<const char *>(sqlite3_column_text(res,0)));
					cout<<"Salrio actual: "<<actual;
				}
				s="select emp.sal from emp where mgr='"+empno+"'";
				error=sqlite3_prepare_v2(conn, s.c_str(),1000,&res,&tail);
				while(sqlite3_step(res) == SQLITE_ROW){
					nuevo=nuevo+atoi(reinterpret_cast<const char *>(sqlite3_column_text(res,0)));
					c++;
				}
				if (c==0){
					nuevo=actual;
				}else{
					nuevo=(nuevo/c)*2;
				}
				stringstream ss;
				ss << nuevo;
				string temp = ss.str();
				cout<<"Salario nuevo: "<<temp<<endl;
				s="update emp set sal='"+temp+"' where empno='"+empno+"'";
				error=sqlite3_exec(conn, s.c_str(),0,0,0);
				if (error!= SQLITE_OK){
					system("cls");
					cout<<"Ocurrio un error al listar los empleados"<<endl;
				}
				cout<<"Salario actualizado"<<endl;
				sqlite3_close(conn);
				system("pause");
				break;
			}
			case '6':{
				system("cls");
				error=sqlite3_open(base.c_str(),&conn);
				cout<<"...:::LISTAR EMPLEADOS DE DEPARTAMENTO:::..."<<endl;
				error=sqlite3_prepare_v2(conn, "select dept.deptno,dept.dname from dept",1000,&res,&tail);
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<sqlite3_column_text(res,0)<<", "<<sqlite3_column_text(res,1)<<endl;
				}
				cout<<endl;
				string deptno;
				cout<<"Deptno del departamento a listar: ";
				cin>>deptno;
				system("cls");
				string s="select * from dept where deptno='"+deptno+"'";
				error=sqlite3_prepare_v2(conn, s.c_str(),1000,&res,&tail);
				cout<<"DEPRATAMENTO:"<<endl<<endl;
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<setw(8)<<"Deptno: "<<sqlite3_column_text(res,0)<<endl<<setw(8)<<"Dname: "<<sqlite3_column_text(res,1)<<endl<<setw(8)<<"Loc: "<<sqlite3_column_text(res,2)<<endl<<endl;
				}
				cout<<endl;
				s="select * from emp where deptno='"+deptno+"'";
				error=sqlite3_prepare_v2(conn, s.c_str(),1000,&res,&tail);
				cout<<"EMPLEADOS:"<<endl<<endl;
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<setw(10)<<"Empno: "<<sqlite3_column_text(res,0)<<endl<<setw(10)<<"Ename: "<<sqlite3_column_text(res,1)<<endl<<setw(10)<<"Job: "<<sqlite3_column_text(res,2)<<endl<<setw(10)<<"Mgr: "<<sqlite3_column_text(res,3)<<endl<<setw(10)<<"Hiredate: "<<sqlite3_column_text(res,4)<<endl<<setw(10)<<"Sal: "<<sqlite3_column_text(res,5)<<endl<<setw(10)<<"Comm: "<<sqlite3_column_text(res,6)<<endl<<setw(10)<<"Deptno: "<<sqlite3_column_text(res,7)<<endl<<endl;
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
			case '7':{
				
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
