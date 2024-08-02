

void loadAndRenderWall(const std::string& filename, char** &art, int &artWidth, int &artHeight) {
    // Deallocate the previous 2D array
    if (art != nullptr) {
        delete2DArray(art, artHeight);
    }

    // Load the new wall
    art = readFileTo2DArray(filename, artWidth, artHeight);
    renderCenteredArt(art, artWidth, artHeight);
}