#include "../headers/Test.h"
using namespace std;

/* Tests */

int CMatriceDoubleTestPrint(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg\n\n";
	MADArg.MATPrint(1);
	return 0;
}

int CMatriceDoubleTestMultConst(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg*10 et 10*MADArg\n\n\n";
	/*
	 *	Calcul puis affichage de l'objet CMatriceDouble temporaire
	 *	Le compilateur utilise MADArg.operator*(10)
	 */
	( MADArg * 10 ).MATPrint(1); //MADArg*10

	cout << endl;
	/*
	 *	Calcul puis affichage de l'objet CMatriceDouble temporaire
	 *	Le compilateur utilise operator*(10, MADArg)
	 *	car 10.operator*(MADArg) n'est pas surchargeable
	 */
	( 10 * MADArg ).MATPrint(1); //10*MADArg
	return 0;
}

int CMatriceDoubleTestDivConst(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg/10 (10/MADArg n'est pas demande)\n\n\n";
	/*
	 *	Calcul puis affichage de l'objet CMatriceDouble temporaire
	 *	Le compilateur utilise MADArg.operator/(10)
	 */
	(MADArg / 10).MATPrint(1); //MADArg/21

	/*
	 *	10/MADArg = 10*MADArg^(-1), donc il faudrait coder une methode pour inverser MADArg
	 *	or, ni cette operation ni cette methode  ne sont demandees dans les specifications
	 */
	return 0;
}

int CMatriceDoubleTestT(CMatriceDouble& MADArg) {
	cout << "Afficher la transposee de MADArg\n\n\n";
	MADArg.MADt().MATPrint(1);
	return 0;
}

int CMatriceDoubleTestAdd(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg + [10 10 10 ... 10]x[10 10 10 ... 10]\n\n\n";
	CMatriceDouble MADDix = CMatriceDouble(MADArg.MATGetDimLigne(), MADArg.MATGetDimColonne());
	(MADArg + (10 * MADDix)).MATPrint();
	return 0;
}

int CMatriceDoubleTestSous(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg - [10 10 10 ... 10]x[10 10 10 ... 10]\n\n\n";
	CMatriceDouble MADDix = 10 * CMatriceDouble(MADArg.MATGetDimLigne(), MADArg.MATGetDimColonne());
	(MADArg - MADDix).MATPrint();
	return 0;
}

int CMatriceDoubleTestMult(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg x MADArg^t\n\n\n";
	CMatriceDouble MADArgT = MADArg.MADt();
	(MADArg * MADArgT).MATPrint();
	return 0;
}
