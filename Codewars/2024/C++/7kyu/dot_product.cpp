/*
 * Vector objects have x, y, and z attributes.
 * Write a function calculating dot product of Vector a and Vector b.
 * Tests round answers to 6 decimal places.
 */
double dot_product(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
