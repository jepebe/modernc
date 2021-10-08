 double derivative(double const x, double (*func) (double)) {
 	double const h = 1e-8;
 	return (func(x + h) - func(x - h)) / (2 * h);
}
