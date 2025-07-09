# Aggiunge l'eseguibile principale del progetto
# Il nome dell'eseguibile sarà "Labprogrammazioneesame"
add_executable(Labprogrammazioneesame
        main.cpp
        ContoCorrente.cpp
        Transazione.cpp
)

# Specifica le directory dove cercare gli header file locali
target_include_directories(Labprogrammazioneesame
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)