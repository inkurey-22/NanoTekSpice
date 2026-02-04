// pipeline {
//   agent any
//
//   environment {
//     CONTAINER = 'your/container:tag'
//     MIRROR_REPO = 'git@github.com:you/mirror-repo.git'
//     MIRROR_SSH_CRED = 'jenkins-key'
//   }
//
//   stages {
//     stage('Checkout') {
//       steps { checkout scm }
//     }
//
//     stage('Compilation (Makefile)') {
//       steps {
//         script {
//           docker.image(env.CONTAINER).inside {
//             sh '''
//               set -e
//               make
//             '''
//           }
//         }
//       }
//     }
//
//     stage('Unit tests (Makefile)') {
//       steps {
//         script {
//           docker.image(env.CONTAINER).inside {
//             sh '''
//               set -e
//               make tests_run
//             '''
//           }
//         }
//       }
//     }
//
//     stage('Clang-tidy') {
//       steps {
//         script {
//           docker.image(env.CONTAINER).inside {
//             sh '''
//               set -e
//               clang-tidy $(find src -name '*.cpp' || true)
//             '''
//           }
//         }
//       }
//     }
//
//     stage('Mirror to repo') {
//       when { expression { currentBuild.currentResult == 'SUCCESS' } }
//       steps {
//         withCredentials([sshUserPrivateKey(credentialsId: env.MIRROR_SSH_CRED, keyFileVariable: 'SSH_KEY', usernameVariable: 'SSH_USER')]) {
//           sh '''
//             set -e
//             eval "$(ssh-agent -s)"
//             ssh-add $SSH_KEY
//             git config user.name "${SSH_USER}"
//             git config user.email "jenkins@inkurey.fr"
//             git remote add mirror ${MIRROR_REPO} || true
//             git fetch mirror || true
//             git push --force-with-lease mirror HEAD:refs/heads/main
//           '''
//         }
//       }
//     }
//   }
//
//   post {
//     failure { echo 'Build or tests failed — not mirroring.' }
//     success { echo 'All done — mirrored to target repo.' }
//   }
// }
