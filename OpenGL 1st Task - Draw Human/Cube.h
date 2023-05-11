class Cube {
public:

    Cube(float centerPosX, float centerPosY, float centerPosZ, float edgeLength)
    {
        float halfSideLength = edgeLength * 0.5f;

        float vertices[] =
        {
            // front face
            centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
            centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top right
            centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom right
            centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

            // back face
            centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top left
            centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
            centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
            centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom left

            // left face
            centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
            centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
            centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
            centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

            // right face
            centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
            centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
            centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
            centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

            // top face
            centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
            centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
            centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // bottom right
            centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // bottom left

            // bot face
            centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // top left
            centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // top right
            centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
            centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength  // bottom left
        };
    }
};