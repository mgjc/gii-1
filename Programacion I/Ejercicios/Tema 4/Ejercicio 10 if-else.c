//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int temp, num;
	
	printf("Escribe un n\243mero:\n");
	scanf("%d", &num);
	temp=num;
	
	if((num/100)>=1){
		if((num/100)==1){
			printf("ciento ");
			temp-=100;
		}else{
			if((num/100)==2){
				printf("doscientos ");
				temp-=200;
			}else{
				if((num/100)==3){
					printf("trescientos ");
					temp-=300;
				}else{
					if((num/100)==4){
						printf("cuatrocientos ");
						temp-=400;
					}else{
						if((num/100)==5){
							printf("quinientos ");
							temp-=500;
						}else{
							if((num/100)==6){
								printf("seiscientos ");
								temp-=600;
							}else{
								if((num/100)==7){
									printf("setecientos ");
									temp-=700;
								}else{
									if((num/100)==8){
										printf("ochocientos ");
										temp-=800;
									}else{
										if((num/100)==9){
											printf("novecientos");
											temp-=900;
										}else{
											printf("el n\243mero no está entre 1 y 999.");
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	if((temp/10)==9){
		printf("noventa ");
		temp-=90;
	}else{
		if((temp/10)==8){
			printf("ochenta ");
			temp-=80;
		}else{
			if((temp/10)==7){
				printf("setenta ");
				temp-=70;
			}else{
				if((temp/10)==6){
					printf("sesenta ");
					temp-=60;
				}else{
					if((temp/10)==5){
						printf("cincuenta ");
						temp-=50;
					}else{
						if((temp/10)==4){
							printf("cuarenta ");
							temp-=40;
						}else{
							if((temp/10)==3){
								printf("treinta ");
								temp-=30;
							}else{
								if((temp/10)==2){
									printf("veint");
									if((temp%10)==0){
										printf("e");
									}else{
										if((temp%10)==1){
											printf("iuno");
										}else{
											if((temp%10)==2){
												printf("idos");
											}else{
												if((temp%10)==3){
													printf("itr\202s");
												}else{
													if((temp%10)==4){
														printf("icuatro");
													}else{
														if((temp%10)==5){
															printf("icinco");
														}else{
															if((temp%10)==6){
																printf("is\202is");
															}else{
																if((temp%10)==7){
																	printf("isiete");
																}else{
																	if((temp%10)==8){
																		printf("iocho");
																	}else{
																		if((temp%10)==9){
																			printf("inueve");
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}else{
									if((temp/10)==1){
										if((temp%10)>5){
											printf("dieci");
											if((temp%10)==9){
												printf("nueve");
											}else{
												if((temp%10)==8){
													printf("ocho");
												}else{
													if((temp%10)==7){
														printf("siete");
													}else{
														printf("s\202is");
													}
												}
											}
										}else{
											if((temp%10)==5){
												printf("quince");
											}else{
												if((temp%10)==4){
													printf("catorce");
												}else{
													if((temp%10)==3){
														printf("trece");
													}else{
														if((temp%10)==2){
															printf("doce");
														}else{
															if((temp%10)==1){
																printf("once");
															}else{
																printf("diez");
															}
														}
													}
												}
											}
										}
									}	
								}
							}
						}
					}
				}
			}
		}
	}
	if(((temp/10)==1)||((temp/10)==2)){
	}else{
		printf("y ");
		if((temp%10)==9){
			printf("nueve");
		}else{
			if((temp%10)==8){
				printf("ocho");
			}else{
				if((temp%10)==7){
					printf("siete");
				}else{
					if((temp%10)==6){
						printf("s\202is");
					}else{
						if((temp%10)==5){
							printf("cinco");
						}else{
							if((temp%10)==4){
								printf("cuatro");
							}else{
								if((temp%10)==3){
									printf("tres");
								}else{
									if((temp%10)==2){
										printf("dos");
									}else{
										if((temp%10)==1){
											printf("uno");
										}else{
											printf("");
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
