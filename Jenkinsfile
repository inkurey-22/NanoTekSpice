pipeline {
  agent any

  environment {
    CONTAINER = 'inkurey22/my-epitest:latest'
    MIRROR_REPO = 'https://github.com/inkurey-22/test.git'
    MIRROR_CRED = 'jenkins-pat'
  }

  stages {
    stage('Checkout') {
      steps { checkout scm }
    }

    stage('Compilation (CMake)') {
      steps {
        script {
          docker.image(env.CONTAINER).inside('-i') {
            sh '''
              #!/bin/bash
              set -euo pipefail
              cmake -S . -B build
              cmake --build build -- -j$(nproc)
            '''
          }
        }
      }
    }

    stage('Mirror to repo') {
      when { expression { currentBuild.currentResult == 'SUCCESS' } }
      steps {
        withCredentials([usernamePassword(credentialsId: env.MIRROR_CRED, usernameVariable: 'GIT_USER', passwordVariable: 'GIT_TOKEN')]) {
          sh '''
            set -e
            git config user.name "jenkins-bot"
            git config user.email "jenkins@inkurey.fr"
            # add remote (use token in URL, avoid showing token in logs)
            git remote add mirror https://$GIT_USER:$GIT_TOKEN@github.com/EpitechPGE2-2025/G-OOP-400-LIL-4-1-tekspice-1.git || true
            git fetch mirror || true
            # push to main
            git push --force-with-lease mirror HEAD:refs/heads/main
          '''
        }
      }
    }
  }

  post {
    failure { echo 'Build or tests failed — not mirroring.' }
    success { echo 'All done — mirrored to target repo.' }
  }
}
